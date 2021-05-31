/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:46:08 by vtorosya          #+#    #+#             */
/*   Updated: 2021/05/31 17:46:10 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stacks *stacks)
{
	if (stacks->count_a <= 3)
		sort_3_element(stacks);
	else if (stacks->count_a <= 5)
		sort_5_element(stacks);
	else
		global_sort(stacks);
}

int		main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	if (!(new = (t_data *)malloc(sizeof(t_data))))
		exit(1);
	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		exit(1);
	null(stacks, new);
	if (validation(argc, argv))
	{
		array_separation(argc, argv, new);
		duplicate_check(new, stacks);
		if (is_sorted(new))
		{
			init_stack(new, stacks);
			sort(stacks);
			free_stack(stacks);
		}
	}
	free(new);
	free(stacks);
	return (0);
}
