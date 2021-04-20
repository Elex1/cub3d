/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melghoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:39:23 by melghoud          #+#    #+#             */
/*   Updated: 2019/11/02 16:42:12 by melghoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tem[len];

	if ((!src && !dst) || len >= (128 * 1024 * 1024))
		return (NULL);
	ft_memcpy(tem, src, len);
	ft_memcpy(dst, tem, len);
	return (dst);
}
