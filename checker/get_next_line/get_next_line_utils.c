/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 06:50:27 by adherrer          #+#    #+#             */
/*   Updated: 2024/04/08 21:28:02 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*src;
	size_t	i;

	i = 0;
	src = malloc ((ft_strlen(s1) + 1) * sizeof(char));
	if (!src)
		return (0);
	while (*s1)
		src[i++] = *s1++;
	src[i] = 0;
	return (src);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if ((size_t)ft_strlen(s) < start)
		return (ft_strdup(""));
	if ((size_t)ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = malloc(len + 1);
	if (!substr)
		return (0);
	while ((i < len) && (len + 1) && (s + start)[i])
	{
		substr[i] = ((s + start)[i]);
		i++;
	}
	if ((len + 1) > 0)
		substr[i] = 0;
	return (substr);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
		if (*s++ == (char)c)
			return ((char *)(s - 1));
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	p;

	p = 0;
	while (s[p])
		p++;
	return (p);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	size_t	size_src;
	size_t	size_dest;

	n = -1;
	size_src = ft_strlen(src);
	size_dest = ft_strlen(dst);
	if (dstsize < size_dest + 1)
		return (size_src + dstsize);
	while (++n < (dstsize - size_dest - 1) && *src)
		*(dst + size_dest + n) = *src++;
	*(dst + size_dest + n) = 0;
	return (size_dest + size_src);
}
