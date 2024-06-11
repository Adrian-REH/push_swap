/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:38:51 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/08 02:47:31 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
#define COMMANDS_H
#include "../push_swap.h"

void swap(t_stack **head, t_stack **both, char c);
void rotate(t_stack **head, t_stack **both, char c);
void rev_rotate(t_stack **head, t_stack **both, char c);
void push(t_stack **dst, t_stack **src, char c);

#endif