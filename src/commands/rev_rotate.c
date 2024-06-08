/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:04:53 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/08 02:59:46 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void			rev_rotate(t_stack *head, t_stack *both, char c)
{

  t_stack	*current;
  t_stack	*tmp;

  if (!head || !((head)->next))
      return ;
  current = head;
  while (current->next->next != NULL)
    current = current->next;
  tmp = current->next;
  current->next = NULL;
  tmp->next = head;
  head = tmp;
  if (c == 'a' && both == NULL)
    write(1, "rra\n", 4);
  else if (c == 'b' && both == NULL)
    write(1, "rrb\n", 4);
  else if (c == 's' && both != NULL)
      (rotate(both, NULL, '\0'), write(1, "rrr\n", 4));
}