/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 09:09:17 by skoh              #+#    #+#             */
/*   Updated: 2021/09/12 13:55:34 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

static void	px_pipes_dispose(int *pipes)
{
	int	*p;

	if (!pipes)
		return ;
	p = pipes + 1;
	while (*p)
		close(*p++);
	free(pipes);
}

// create and rearrange pipes for commands
// eg 4 commands share 3 pipes internally
// this function will arrange following
// 3 pipes:  r1,w1 r2,w2 r3,w3
// array  :x,w1,r1,w2,r2,w3,r3,x
// command: 0  |  1  |  2  |  3

// 1 pipes:   r1,w1
// array:   fi,w1,r1,fo
// cmd:      1  |  2
static int	*px_pipes_create(int count)
{
	int	i;
	int	*pipes;

	pipes = ft_calloc(count * 2, sizeof(int));
	if (!pipes)
		return (NULL);
	i = -1;
	while (++i < count - 1)
	{
		if (pipe(pipes + i * 2 + 1))
			return (px_pipes_dispose(pipes), NULL);
		ft_swap(pipes + i * 2 + 1, pipes + i * 2 + 2, sizeof(int));
	}
	return (pipes);
}

static int	px_heredoc(char *delimiter, int fd)
{
	char		*line;
	const char	*prompt = "pipe heredoc> ";

	ft_putstr_fd(prompt, STDOUT_FILENO);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_strcmp(line, delimiter) == 0)
			break ;
		ft_putendl_fd(line, fd);
		free(line);
		ft_putstr_fd(prompt, STDOUT_FILENO);
	}
	free(line);
	close(fd);
	return (1);
}

// wait all children
// while ((pid = wait(&status)) > 0)
// 	ft_printf_fd(2, "wait pid %d status %d\n", pid, status);

// return status of last child
// parameters: file-in cmd1   cmd2   file-out
// argv		:     0		1		2		3
// fd array:		  fi,w1   r1,fo

// heredoc delimiter cmd1    cmd2 file-append
//    0        1       2      3        4
//            0,w1   r1,w2  r2,fo
static int	px_run(int count, char **argv, char **env, char *infile)
{
	int		i;
	int		*pipes;
	pid_t	pid;
	int		is_bonus;

	is_bonus = ft_strcmp(infile, "here_doc") == 0;
	pipes = px_pipes_create(count);
	i = -1;
	if (is_bonus && px_heredoc(argv[0], pipes[1]))
		i++;
	while (++i < count)
	{
		pid = fork();
		if (pid == 0)
		{
			if (!px_replace_stdio(pipes + i * 2, infile, argv[count], is_bonus))
				return (px_pipes_dispose(pipes), EXIT_FAILURE);
			px_pipes_dispose(pipes);
			return (px_execfile(argv[i], env));
		}
	}
	px_pipes_dispose(pipes);
	waitpid(pid, &i, 0);
	return (!!i);
}

int	main(int argc, char **argv, char **env)
{
	int	status;

	status = EXIT_SUCCESS;
	if (argc < 5)
		ft_putendl_fd("Error\nRequire 4 or more parameters\n"
			"Syntax        : ./pipex file1 cmd1 cmd2 file2\n"
			"Equivalent    : < file1 cmd1 | cmd2 > file2\n"
			"Bonus syntax 1: ./pipex < file1 cmd1 cmd2 cmd3 ... cmdn file2\n"
			"Equivalent    : < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2\n"
			"Bonus syntax 2: ./pipex here_doc LIMITER cmd cmd1 file\n"
			"Equivalent    : cmd << LIMITER | cmd1 >> file",
			STDERR_FILENO);
	else
		status = px_run(argc - 3, argv + 2, env, argv[1]);
	if (0)
		system(">&2 leaks -quiet -fullContent pipex");
	return (status);
}
