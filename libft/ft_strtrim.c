/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melghoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:17:02 by melghoud          #+#    #+#             */
/*   Updated: 2019/10/31 13:38:45 by melghoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp1(char const *s1, char const *s2)
{
	int	b;
	int	c;
	int	nb;

	b = 0;
	c = 0;
	while (s1[b] != '\0')
	{
		while (s2[c] != '\0')
		{
			nb = s1[b] - s2[c];
			if (nb == 0)
				break ;
			else
				c++;
		}
		c = 0;
		if (nb != 0)
			break ;
		else
			b++;
	}
	return (b);
}

int		ft_strcmp2(char const *s1, char const *s2)
{
	int i;
	int a;
	int nb;
	int c;

	c = 0;
	a = 0;
	i = ft_strlen(s1) - 1;
	while (i >= a)
	{
		while (s2[c] != '\0')
		{
			nb = s1[i] - s2[c];
			if (nb == 0)
				break ;
			else
				c++;
		}
		c = 0;
		if (nb != 0)
			break ;
		else
			i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	int		b;
	int		d;
	char	*dst;

	d = 0;
	b = ft_strcmp1(s1, set);
	i = ft_strcmp2(s1, set);
	if ((i - b + 1) < 0)
	{
		b = 1;
		dst = (char *)malloc(sizeof(char) * 1);
		if (dst == NULL)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	len = i - b + 1;
	dst = ft_substr(s1, b, len);
	return (dst);
}
