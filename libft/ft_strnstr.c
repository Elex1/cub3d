/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melghoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 23:11:04 by melghoud          #+#    #+#             */
/*   Updated: 2019/11/02 16:11:51 by melghoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		j;
	size_t	i;
	char	*s;
	char	*to_find;

	if (!haystack && len == 0)
		return (0);
	if (*needle == '\0')
		return ((char *)haystack);
	s = (char *)haystack;
	to_find = (char *)needle;
	i = 0;
	while (s[i] && (i < len))
	{
		j = 0;
		while (s[i + j] == to_find[j] && (i + j < len))
		{
			if (to_find[j + 1] == '\0')
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
