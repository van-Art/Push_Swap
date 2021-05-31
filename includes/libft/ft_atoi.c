/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:43:00 by vtorosya          #+#    #+#             */
/*   Updated: 2021/05/31 17:43:02 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		dig;
	long	res;

	sign = 1;
	dig = 0;
	res = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v'
		|| *str == ' ' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		res = res * 10 + (*str - '0');
		dig++;
		if (dig > 10 || (res * sign) > MAXINT || (res * sign) < MININT)
			ft_error();
		str++;
	}
	return (int)(res * sign);
}
