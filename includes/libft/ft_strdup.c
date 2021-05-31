/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:44:12 by vtorosya          #+#    #+#             */
/*   Updated: 2021/05/31 17:44:13 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		i;

	i = 0;
	if (!(a = (char *)malloc(sizeof(*s1) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
