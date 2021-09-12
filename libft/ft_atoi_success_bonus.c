/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_success_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:03:25 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:03:26 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// atoi with format & overflow/underflow checking
// return true if 1) not overflow/underflow, 2) format " *[+-]?[0-9]+"

int	ft_atoi_success(const char *str, int *out)
{
	*out = ft_atoi(str);
	while (ft_isspace(*str))
		str++;
	if (*out == -(*str != '-'))
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
		str++;
	return (*str == '\0');
}
