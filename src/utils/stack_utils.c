/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:18:36 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/08 03:39:01 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	count_r(t_node *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->s_index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	push_stack(t_stack *stack, int index, int data)
{
	t_node	*tmp;
 
	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->data = data;
	tmp->s_index = index;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->size++;
}