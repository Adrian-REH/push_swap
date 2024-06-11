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
#define UTILS_H
#include "../push_swap.h"

int count_r(t_stack *stack, int index);
int *parse(int argc, char **argv, int count);
int check_digits(int argc, char **argv);
int ft_index(int n, int *arr);
int ft_sqrt(int number);
int checkd_bf(int *numbers, int count);
int is_sorted(t_stack *stack);

#endif