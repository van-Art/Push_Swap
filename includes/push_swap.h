/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <vtorosya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:45:11 by vtorosya          #+#    #+#             */
/*   Updated: 2021/05/31 17:45:12 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct		s_steps
{
	int				count_a;
	int				count_b;
	int				dest_a;
	int				dest_b;
}					t_steps;

typedef struct		s_data
{
	int				a[10000];
	int				count_element;
}					t_data;

typedef struct		s_stack
{
	int				data;
	int				step;
	int				rotate;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	int				count_a;
	int				count_b;
	int				min;
	int				max;
	int				med;
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

int					only_spaces(const char *str);
int					is_sorted(t_data *new);
void				rrr(t_stacks *s, int i);

int					validation(int argc, char **argv);
void				number_availability(const char *str);
void				valid_str(const char *str);
void				duplicate_check(t_data *new, t_stacks *stacks);
void				search_duplicate(const int *dup, int count);

void				array_separation(int argc, char **argv, t_data *new);
void				stacking(t_data *new, int *buff, int count);

void				init_stack(t_data *new, t_stacks *stacks);
t_stack				*create_stack(const int *buff, int count);
void				free_stack(t_stacks *stacks);
void				sort(t_stacks *stacks);
void				null(t_stacks *stacks, t_data *new);

void				sort_3_element(t_stacks *stacks);
void				sort_5_element(t_stacks *stacks);
int					max(t_stack *s);

void				quick_sort(int *array, int start, int end);
int					partition(int *array, int start, int end);

void				global_sort(t_stacks *stacks);
void				start_sort(t_stacks *stacks);
void				steps_markup(t_stack *b, int count);
void				minimum_insertion_steps(t_stacks *stacks,
							t_steps *steps);
void				instruction_execution(t_stacks *stacks, t_steps *steps);

void				help_finding_place(t_stacks *s, t_stack *b,
							int *action, int *buff);
int					finding_place(t_stacks *s, t_stack *b,
							t_steps *steps, int min);
int					smaller_element_detection(t_stack *a, int buff, int src);
int					count_to_min(t_stack *a, int min);

void				ra(t_stack **a, int i);
void				rb(t_stack **b, int i);
void				rr(t_stacks *s, int i);
void				rra(t_stack **a, int i);
void				rrb(t_stack **b, int i);

void				sa(t_stack *a, int i);
void				sb(t_stack *a, int i);
void				ss(t_stacks *s, int i);
void				pa(t_stacks *s, int i);
void				pb(t_stacks *s, int i);

int					stack_sorted(t_stacks *s);
void				read_action(t_stacks *s);
void				action_processing(char *line, t_stacks *s);

#endif
