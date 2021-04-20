/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melghoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:11:46 by melghoud          #+#    #+#             */
/*   Updated: 2019/11/03 15:34:12 by melghoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	if (src && dst)
	{
		while (src[len] != '\0')
			len++;
		if (size > 0)
		{
			while (i < size - 1 && src[i] != '\0')
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
		return (len);
	}
	return (0);
}
