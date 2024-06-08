/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:14:29 by adherrer          #+#    #+#             */
/*   Updated: 2024/03/20 20:42:17 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	len;
	size_t	n;

	if ((!*s1 && !*set) || (!*s1 && *set))
		return (ft_strdup(""));
	len = ft_strlen(s1);
	n = 0;
	while (ft_strchr(set, s1[len - 1]))
		len--;
	while (ft_strchr(set, s1[n]))
		n++;
	res = ft_substr(s1, n, len - n);
	return (res);
}
/* 
int main()
{
	char	*str = ft_strtrim("lorem ipsum dolor sit amet","te");
}  */