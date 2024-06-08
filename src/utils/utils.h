/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:19:46 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/08 03:41:51 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int     count_r(t_stack *stack, int index);
int     *parse(int argc, char **argv, int count);
int     check_digits(int argc, char **argv);
void	push_stack(t_stack *stack, int index, int data);
int     ft_index(int n, int *arr);

#endif