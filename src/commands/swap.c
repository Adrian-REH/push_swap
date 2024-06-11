/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:53:45 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/08 02:58:34 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void swap(t_stack **stack, t_stack **both, char c)
{
  t_stack *tmp;

  if (!stack || !(*stack)->next)
    return;
  tmp = *stack;
  *stack = (tmp->next);
  tmp->next = (*stack)->next;
  (*stack)->next = tmp;
  if (c == 'a' && both == NULL)
    write(1, "ra\n", 3);
  else if (c == 'b' && both == NULL)
    write(1, "ra\n", 3);
  else if (c == 's' && both != NULL)
  {
    swap(both, NULL, '\0');
    write(1, "ss\n", 3);
  }
}
