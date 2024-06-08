/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:49:09 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/08 03:09:30 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void    push(t_stack *dst, t_stack *src, char c)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!tmp)
		return ;
	tmp->data = src->data;
	tmp->s_index = src->s_index;
	tmp->next = dst;
	dst = tmp;
    if (c == 'a')
        write(1, "pa\n", 3);
    else if (c == 'b')
        write(1, "pb\n", 3);
}
