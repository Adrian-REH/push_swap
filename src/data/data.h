/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:26:50 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/15 13:26:55 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "../push_swap.h"

void	push_stack(t_stack **stack, int index, int data);
int		pop_stack(t_stack **stack);
void	free_stack(t_stack *stack);
void	ft_freedom(char **dst);
void	ins_sort(int array[], int n);

#endif