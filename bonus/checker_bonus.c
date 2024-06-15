/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:09:09 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/15 15:05:16 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "data/data_bonus.h"
#include "../src/push_swap.h"
#include "../src/commands/commands.h"
#include "../src/utils/utils.h"
#include "../src/data/data.h"
#include "../src/exceptions/exceptions.h"
//
// void print_stacks(t_stack **stack_a, t_stack **stack_b)
// {
//     t_stack *tmp_a;
//     t_stack *tmp_b; 
//     tmp_a = *stack_a;
//     tmp_b = *stack_b;
//     printf("Stack A | Stack B\n");
//     while (tmp_a || tmp_b)
//     {
//         if (tmp_b != NULL && tmp_a != NULL)
//         {
//           printf("%d | %d\n",(tmp_a)->data, (tmp_b)->data);
//           (tmp_b) = (tmp_b)->next; 
//           (tmp_a) = (tmp_a)->next; 
//         }
//         else if (tmp_b != NULL && tmp_a == NULL)
//         {
//           printf("0 | %d\n",(tmp_b)->data);
//           (tmp_b) = (tmp_b)->next; 
//         }
//         else if (tmp_b == NULL && tmp_a != NULL)
//         {
//           printf("%d | 0\n",(tmp_a)->data);
//           (tmp_a) = (tmp_a)->next; 
//         }
//     }
// }

static void	init(t_stack **stack_a, int *nb, int c)
{
	int	i;

	i = c - 1;
	while (i >= 0)
		(push_stack(stack_a, 0, nb[i]), i--);
}

static void	read_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		else if (is_command(str))
		{
			exeute_command(stack_a, stack_b, str);
			free(str);
		}
		else
		{
			free(str);
			return ;
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count;
	int		*numbers;

	stack_a = NULL;
	stack_b = NULL;
	count = check_digits(argc, argv);
	numbers = parse(argc, argv, count);
	if (count <= 1 || checkd_bf(numbers, count))
	{
		free(numbers);
		if (count == 1)
			display_error("Error: Un numero", 1);
		display_error("Error: Numeros repetidos", 1);
	}
	init(&stack_a, numbers, count);
	read_and_execute(&stack_a, &stack_b);
	if (is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(numbers);
	free_stack(stack_a);
}
