/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:07:39 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/08 02:13:35 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

int exception_syntax(char *str_n);
int exception_duplicate(t_stack *a, int n);
void display_error(char *error_msg, int yeet);

#endif