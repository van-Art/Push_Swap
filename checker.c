/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:45:26 by vtorosya          #+#    #+#             */
/*   Updated: 2021/05/31 17:45:28 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_processing(char *line, t_stacks *s)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(s->a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(s->b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(s, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(s, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(s, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(&s->a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(&s->b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(s, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(&s->a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(&s->b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(s, 0);
	else
		ft_error();
}

void	read_action(t_stacks *s)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		action_processing(line, s);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int		stack_sorted(t_stacks *s)
{
	int		i;
	int		buff;
	t_stack	*save;

	i = 0;
	save = s->a;
	while (i < (s->count_a - 1))
	{
		buff = s->a->data;
		s->a = s->a->next;
		if (buff > s->a->data)
		{
			s->a = save;
			return (0);
		}
		i++;
	}
	s->a = save;
	return (1);
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
		init_stack(new, stacks);
		read_action(stacks);
		if ((stack_sorted(stacks)) && stacks->count_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_stack(stacks);
	free(new);
	free(stacks);
	return (0);
}
