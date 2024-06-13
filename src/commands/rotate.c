/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:02:23 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/08 03:03:24 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void rotate(t_stack **head, t_stack **both, char c)
{
  t_stack *tmp;
  t_stack *current;

  if (*head == NULL || ((*head)->next == NULL))
    return;
  tmp = *head;
  *head = tmp->next;
  current = *head;
  while (current->next != NULL)
    current = current->next;
  current->next = tmp;
  tmp->next = NULL;
  if (c == 'a' && both == NULL)
    write(1, "ra\n", 3);
  else if (c == 'b' && both == NULL)
    write(1, "rb\n", 3);
  else if (c == 's' && both != NULL)
    (rotate(both, NULL, '\0'), write(1, "rr\n", 3));
  else if (!c && both != NULL)
    (rotate(both, NULL, '\0'));
}