/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melghoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:07:59 by melghoud          #+#    #+#             */
/*   Updated: 2019/11/03 15:45:05 by melghoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	j;
	int		x;

	i = 0;
	x = 1;
	j = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == 45)
			x *= -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		j = j * 10 + str[i] - 48;
		if (j * x > 0 && x < 0)
			return (0);
		if (j * x < 0 && x > 0)
			return (-1);
		i++;
	}
	return ((int)j * x);
}
