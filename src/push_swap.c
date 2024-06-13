/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:17:55 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/08 03:43:48 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils/utils.h"
#include "commands/commands.h"
#include "algorithms/algorithms.h"
#include "data/data.h"
#include "exceptions/exceptions.h"

t_stack *sort(t_stack *stack_a, t_stack *stack_b, int *numbers, int length)
{
	if (is_sorted(stack_a))
	{
		free(numbers);
		free_stack(stack_a);
		display_error("Error: Stack ordenado", 1);
	}
	if (length == 2)
		swap(&stack_a, NULL, 'a');
	else if (length == 3)
		simple_sort(&stack_a, length);
	else if (length <= 7)
		s_insertion_sort(stack_a, stack_b, length);
	else if (length > 7)
	{

		k_sort1(&stack_a, &stack_b, length);
		k_sort2(stack_a, stack_b, length);
	}
	else
		display_error("Error no hay numeros\n", 1);
	return stack_a;
}

t_stack *init(t_stack *stack_a, int *nb, int c)
{
	int i;
	t_stack *tmp;

	i = c - 1;
	while (i >= 0)
	{
		stack_a = push_stack(stack_a, 0, nb[i]);
		i--;
	}
	ins_sort(nb, c);
	i = 0;
	tmp = stack_a;

	while (tmp)
	{
		tmp->s_index = ft_index(tmp->data, nb);
		tmp = tmp->next;
	}
	return stack_a;
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int count;
	int *numbers;

	if (ac == 1)
		display_error("Error: no se pasaron numeros\n", 1);
	stack_a = NULL;
	stack_b = NULL;
	count = check_digits(ac, av);
	numbers = parse(ac, av, count);
	if (count <= 1 || checkd_bf(numbers, count))
	{
		free(numbers);
		if (count == 1)
			display_error("Error: Un numero", 1);
		display_error("Error: Numeros repetidos", 1);
	}
	stack_a = init(stack_a, numbers, count);
	stack_a = sort(stack_a, stack_b, numbers, count);
	free(numbers);
	free_stack(stack_a);
	return (0);
}
