/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:35:21 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/08 01:40:44 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

void k_sort1(t_stack **stack_a, t_stack **stack_b, int length);
t_stack *k_sort2(t_stack *stack_a, t_stack *stack_b, int length);
void s_insertion_sort(t_stack **stack_a, t_stack **stack_b, int length);
void simple_sort(t_stack **stack, int length);

#endif