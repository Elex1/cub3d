/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melghoud <melghoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:53:55 by melghoud          #+#    #+#             */
/*   Updated: 2021/04/21 16:54:42 by melghoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	value_at(int i, int j, t_struct *data)
{
	if (valid_indices(data, j, i))
		return (data->map[i][j]);
	return (' ');
}

int	check_element(t_struct *data, int i, int j)
{
	int	x;
	int	z;

	x = -1;
	while (x <= 1)
	{
		z = -1;
		while (z <= 1)
		{
			if (value_at(i + x, j + z, data) == ' ')
				return (FALSE);
			z++;
		}
		x++;
	}
	return (TRUE);
}

void	check_map(t_struct *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->n_lines)
	{
		j = -1;
		while (++j < data->g_lines_length[i])
		{
			if (!(data->map[i][j] == '1' || data->map[i][j] == ' ')
					&& !check_element(data, i, j))
				error("\e[0;31m Tle3 Tshlel!\n");
		}
	}
}
