/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:46:50 by vtorosya          #+#    #+#             */
/*   Updated: 2021/05/31 17:46:52 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		validation(int argc, char **argv)
{
	int i;
	int ret;

	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (only_spaces(argv[i]))
		{
			number_availability(argv[i]);
			valid_str(argv[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}

void	number_availability(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	ft_error();
}

void	valid_str(const char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				ft_error();
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-') &&
				(sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

void	duplicate_check(t_data *new, t_stacks *stacks)
{
	int			*dup;

	if (!(dup = (int *)malloc(sizeof(int) * (new->count_element))))
		exit(1);
	dup = ft_intcpy(dup, new->a, new->count_element);
	quick_sort(dup, 0, new->count_element - 1);
	search_duplicate(dup, new->count_element - 1);
	stacks->count_a = new->count_element;
	stacks->count_b = 0;
	stacks->min = dup[0];
	stacks->med = dup[new->count_element / 2];
	stacks->max = dup[new->count_element - 1];
	free(dup);
}

void	search_duplicate(const int *dup, int count)
{
	int i;

	i = 0;
	while (i != count)
	{
		if (dup[i] == dup[i + 1])
			ft_error();
		i++;
	}
}
