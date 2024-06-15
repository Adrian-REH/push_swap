/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:16:35 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/15 13:22:35 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "algorithms.h"
#include "../commands/commands.h"
#include "../utils/utils.h"

int	is_rot_sort(t_stack *stack, int min_s_index)
{
	int	a;
	int	b;
	int	c;

	(void)min_s_index;
	a = stack->data;
	b = stack->next->data;
	c = stack->next->next->data;
	if (a < b && b < c)
		return (1);
	if (b < c && a > c)
		return (1);
	if (c < a && a < b)
		return (1);
	return (0);
}

void	simple_sort(t_stack **stack, int length)
{
	int	min_s_index;
	int	r;

	if (is_sorted(*stack))
		return ;
	min_s_index = get_min_index(*stack);
	r = count_r(*stack, min_s_index);
	if (is_rot_sort(*stack, min_s_index))
	{
		if (r < length - r)
			rotate(stack, NULL, 'a');
		else
			rev_rotate(stack, NULL, 'a');
	}
	else
	{
		swap(stack, NULL, 'a');
		if (is_sorted(*stack))
			return ;
		if (r < length - r)
			rotate(stack, NULL, 'a');
		else
			rev_rotate(stack, NULL, 'a');
	}
}

void	s_insertion_sort(t_stack **stack_a, t_stack **stack_b, int length)
{
	int	min_index;
	int	iter;
	int	n;

	iter = 0;
	n = length;
	while (iter++ < n - 3)
	{
		min_index = get_min_index((*stack_a));
		if (count_r((*stack_a), min_index) <= n - min_index - \
				count_r((*stack_a), min_index))
			while ((*stack_a)->s_index != min_index)
				rotate(stack_a, NULL, 'a');
		else
			while ((*stack_a)->s_index != min_index)
				rev_rotate(stack_a, NULL, 'a');
		push(stack_b, stack_a, 'b');
		length--;
	}
	simple_sort(stack_a, length);
	iter = 0;
	while (iter++ < n - 3)
		push(stack_a, stack_b, 'a');
}
