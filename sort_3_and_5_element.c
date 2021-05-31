/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_and_5_element.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:46:35 by vtorosya          #+#    #+#             */
/*   Updated: 2021/05/31 17:46:36 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_element(t_stacks *stacks)
{
	int mmax;

	mmax = max(stacks->a);
	if (stacks->count_a == 1)
		return ;
	else if (stacks->count_a == 2)
	{
		if (stacks->a->data > stacks->a->next->data)
			sa(stacks->a, 1);
		return ;
	}
	else if (stacks->count_a == 3)
	{
		if (stacks->a->data == mmax)
			ra(&stacks->a, 1);
		if (stacks->a->next->data == mmax)
			rra(&stacks->a, 1);
		if (stacks->a->data > stacks->a->next->data)
			sa(stacks->a, 1);
	}
}

void	sort_5_element(t_stacks *stacks)
{
	while (stacks->count_b < 2)
	{
		if (stacks->a->data == stacks->min || stacks->a->data == stacks->max)
			pb(stacks, 1);
		else
			ra(&stacks->a, 1);
	}
	sort_3_element(stacks);
	pa(stacks, 1);
	pa(stacks, 1);
	if (stacks->a->data == stacks->max)
	{
		ra(&stacks->a, 1);
	}
	else
	{
		sa(stacks->a, 1);
		ra(&stacks->a, 1);
	}
}

int		max(t_stack *s)
{
	int max;

	max = s->data;
	while (s)
	{
		if (s->data > max)
			max = s->data;
		s = s->next;
	}
	return (max);
}
