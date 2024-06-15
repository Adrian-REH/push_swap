/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:27:24 by adherrer          #+#    #+#             */
/*   Updated: 2024/06/15 17:53:13 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../src/exceptions/exceptions.h"

static int	ft_isspaces(char str)
{
	return ((str <= 13 && str >= 9) || str == ' ');
}

int	ft_atoi(const char *str)
{
	int		sign;
	long int	num;

	num = 0;
	sign = 1;
	while (ft_isspaces(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (ft_isdigit(*str))
		num = num * 10 - 48 + *str++;
	if (num > __INT_MAX__)
		display_error("Error: Es un maximo\n", 1);	
	return (((int)num) * sign);
}
/* int	main()
{
	int	p = ft_atoi("9") + 48;
	write(1, p, 1);

} */