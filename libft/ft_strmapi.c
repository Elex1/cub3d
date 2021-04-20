/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melghoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:28:35 by melghoud          #+#    #+#             */
/*   Updated: 2019/10/31 23:20:58 by melghoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new_s;

	i = 0;
	new_s = 0;
	if (s)
	{
		new_s = (char *)malloc(ft_strlen(s) + 1);
		if (new_s == 0)
			return (0);
		while (s[i] != '\0')
		{
			new_s[i] = f(i, ((char *)s)[i]);
			i++;
		}
		new_s[i] = '\0';
	}
	return (new_s);
}
