/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:40:49 by Koh               #+#    #+#             */
/*   Updated: 2021/05/28 11:20:07 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

/*
** find fd or insert by descending order
**
** variables l & n as parameters to esc norm
** condition before optimized
** if (!*list || l->fd == fd || l->fd < fd || !l->next || l->next->fd < fd)
*/

static t_fd	*gnl_get_fd(t_fd **list, int fd)
{
	t_fd	*l;
	t_fd	*n;

	l = *list;
	while (l && l->fd > fd && l->next && l->next->fd >= fd)
		l = l->next;
	if (l && l->fd == fd)
		return (l);
	n = (t_fd *)malloc(sizeof(t_fd));
	if (!n)
		return (NULL);
	*n = (t_fd){.fd = fd};
	if (!l || l->fd < fd)
	{
		n->next = l;
		*list = n;
	}
	else
	{
		n->next = l->next;
		l->next = n;
	}
	return (n);
}

/*
** read file into new buffer, resize buffer if low-utilisation
** return 0 if read or malloc error (-1), otherwise 1
**
** variables buf, dst, buf_read as paramters to ecs norm
** t->success = -1 if buf allocation fails, or read fails
** t->success = 0 if read EOF
** t->success > 0 if read > 0
*/

static int	gnl_read_file(t_fd *t)
{
	void	*new_buf;
	int		read_len;

	new_buf = (char *)malloc(BUFFER_SIZE + t->len);
	if (!new_buf)
		return (0);
	read_len = read(t->fd, new_buf + t->len, BUFFER_SIZE);
	t->eof = (read_len == 0);
	if (read_len > 0)
	{
		ft_memcpy(new_buf, t->buf + t->pos, t->len);
		free(t->buf);
		t->buf = new_buf;
		t->len += read_len;
		t->pos = 0;
	}
	else
		free(new_buf);
	return (read_len != -1);
}

/*
** return new string if \n found, or remaining string if error or EOF
** POSIX text file should ended with \n, so EOF always return empty string
** file not ended \n will have remaining text with EOF
** otherwise return NULL to retry after read-file
*/

static char	*gnl_find_line(t_fd *t)
{
	char		*line;
	char		*newline;
	size_t		line_len;

	if (t->eof)
	{
		if (t->len)
			line = ft_strndup(t->buf + t->pos, t->len);
		else
			line = NULL;
		free(t->buf);
		t->buf = NULL;
		t->len = 0;
		t->pos = 0;
		return (line);
	}
	newline = (char *)ft_memchr(t->buf + t->pos, '\n', t->len);
	if (!newline)
		return (NULL);
	line_len = newline - t->buf - t->pos;
	line = ft_strndup(t->buf + t->pos, line_len);
	t->pos += line_len + 1;
	t->len -= line_len + 1;
	return (line);
}

/*
** remove from linkedlist, then
** free buffter and fd struct, then
** return fd status
*/

static int	gnl_free_fd(t_fd **list, t_fd *t, const int ret)
{
	t_fd	*l;

	if (*list == t)
		*list = t->next;
	else
	{
		l = *list;
		while (l && l->next != t)
			l = l->next;
		l->next = t->next;
	}
	free(t->buf);
	free(t);
	return (ret);
}

/*
** parameter line returned as NULL or new string. both are free()-safe
** caller should always free(line) after each get_next_line(fd, &line)
** malloced linkedlist, buffer are free when get_next_line() returns 0 or -1
**
** small buffer reduce buffer wastage, but more malloc
** bigger buffer likely bigger wastage, but lesser malloc
*/

int	get_next_line(int fd, char **line)
{
	static t_fd	*list;
	t_fd		*st;

	if (line)
		*line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	st = gnl_get_fd(&list, fd);
	while (st)
	{
		*line = gnl_find_line(st);
		if (st->eof)
			return (gnl_free_fd(&list, st, 0));
		if (*line)
			return (1);
		if (!gnl_read_file(st))
			return (gnl_free_fd(&list, st, -1));
	}
	return (-1);
}
