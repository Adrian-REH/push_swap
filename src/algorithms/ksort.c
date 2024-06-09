/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:16:23 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/08 02:21:33 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../utils/utils.h"
#include "../commands/commands.h"

void k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int i;
	int range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (stack_a)
	{
		if (stack_a->s_index <= i)
		{
			push(stack_b, stack_a, 'b');
			i++;
		}
		else if (stack_a->s_index <= i + range)
		{
			push(stack_b, stack_a, 'b');
			i++;
			if (!(stack_a->s_index <= i + range))
				rotate(stack_a, stack_b, 's');
			else
				rotate(stack_b, NULL, 'b');
		}
		else
			rotate(stack_a, NULL, 'a');
	}
}

void k_sort2(t_stack *stack_a, t_stack *stack_b, int length)
{
	int rb_count;
	int rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_r(stack_b, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->s_index != length - 1)
				rotate(stack_b, NULL, 'b');
			push(stack_a, stack_b, 'a');
			length--;
		}
		else
		{
			while (stack_b->s_index != length - 1)
				rev_rotate(stack_b, NULL, 'b');
			push(stack_a, stack_b, 'a');
			length--;
		}
	}
}
