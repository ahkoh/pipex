/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:03:37 by skoh              #+#    #+#             */
/*   Updated: 2021/09/08 21:36:26 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// prev num to detect overflow by new-sum / 10 == prev-sum
// -1 for overflow positive num
// 0 for overflow negative num

int	ft_atoi(const char *str)
{
	int	sum;
	int	is_negative;
	int	prev;

	prev = (is_negative = (sum = 0));
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		is_negative = (*str++ == '-');
	while (ft_isdigit(*str))
	{
		if (is_negative)
			sum = sum * 10 - (*str++ - '0');
		else
			sum = sum * 10 + (*str++ - '0');
		if (sum / 10 == prev)
			prev = sum;
		else
			return (-!is_negative);
	}
	return (sum);
}
