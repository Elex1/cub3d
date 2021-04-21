/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melghoud <melghoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:15:34 by melghoud          #+#    #+#             */
/*   Updated: 2021/04/21 16:15:37 by melghoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_not_valid_element(t_struct *data, const char *buff)
{
	return (buff[data->pos] != '1' && buff[data->pos] != '0' \
	&& buff[data->pos] != '2' && buff[data->pos] != 'N' \
	&& buff[data->pos] != 'W' && buff[data->pos] != 'E' \
	&& buff[data->pos] != 'S' && buff[data->pos] != ' ');
}

int	is_player(t_struct *data, const char *buff)
{
	return (buff[data->pos] == 'N' || buff[data->pos] == 'W'
		|| buff[data->pos] == 'E' || buff[data->pos] == 'S');
}

int	is_sprite(char c)
{
	return (c == '2');
}

int	valid_indices(t_struct *data, int x, int y)
{
	if (y >= data->n_lines || y < 0)
		return (FALSE);
	if (x >= data->g_lines_length[y] || x < 0)
		return (FALSE);
	return (TRUE);
}

int	if_wall(float x, float y, t_struct *data)
{
	int	map_index_x;
	int	map_index_y;

	map_index_x = calculate_index(x);
	map_index_y = calculate_index(y);
	if (!valid_indices(data, map_index_x, map_index_y))
		return (TRUE);
	if (((int)y < 0 || (int)y > data->m_height)
		|| (map_index_y > data->n_lines))
		return (TRUE);
	return (data->map[map_index_y][map_index_x] == ' '
	|| data->map[map_index_y][map_index_x] == '1');
}
