/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:26:26 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/08 03:29:03 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				return (-1);
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' ' || argv[i][j
					+ 1] == '\0'))
				count += 1;
			j++;
		}
		i++;
	}
	return (count);
}
int	*parse(int argc, char **argv, int count)
{
	char	**s_numbers;
	int		*numbers;
	int		i;
	int		j;
	int		k;

	numbers = (int *)malloc(sizeof(int) * count);
	if (!numbers)
		return (NULL);
	i = 0;
	j = 0;
	while (++i < argc)
	{
		s_numbers = ft_split(argv[i], ' ');
		if (!s_numbers)
			display_error("", 1);
		// check_range(s_numbers, numbers);
		k = 0;
		while (s_numbers[k])
			numbers[j++] = ft_atoi(s_numbers[k++]);
		// free_2d(s_numbers);
	}
	return (numbers);
}
