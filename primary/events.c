/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melghoud <melghoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:16:40 by melghoud          #+#    #+#             */
/*   Updated: 2021/04/21 16:33:28 by melghoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	func(int *v, int x1, int x2)
{
	if (*v == 0)
		*v = x1;
	else
		*v = x2;
}

int	hud_key_pressed(int keycode, t_struct *data)
{
	if (keycode == 15)
		func(&data->reset, 1, 0);
	if (keycode == 257)
		func(&data->shift, 1, 0);
	if (keycode == 46)
		func(&data->m, 1, 0);
	if (keycode == 4)
		func(&data->h, 1, 0);
	if (keycode == 17)
		func(&data->t, 1, 0);
	if (keycode == 53)
	{
		destruct(data);
		ft_close(data);
	}
	return (TRUE);
}

int	key_pressed(int keycode, t_struct *data)
{
	hud_key_pressed(keycode, data);
	if (keycode == 0)
	{
		data->left = (M_PI * 0.5F) * (-1);
		data->walk_direction = 1;
	}
	if (keycode == 2)
	{
		data->left = M_PI * 0.5F;
		data->walk_direction = 1;
	}
	if (keycode == 13 || keycode == 126)
		data->walk_direction = 1;
	if (keycode == 1 || keycode == 125)
		data->walk_direction = -1;
	if (keycode == 124)
		data->turn_direction = 1;
	if (keycode == 123)
		data->turn_direction = -1;
	return (TRUE);
}

int	key_released(int keycode, t_struct *data)
{
	if (keycode == 15)
		func(&data->reset, 0, 1);
	if (keycode == 257)
		func(&data->shift, 0, 1);
	if (keycode == 13 || keycode == 126)
		data->walk_direction = 0;
	if (keycode == 1 || keycode == 125)
		data->walk_direction = 0;
	if (keycode == 124)
		data->turn_direction = 0;
	if (keycode == 123)
		data->turn_direction = 0;
	if (keycode == 0)
	{
		data->left = 0;
		data->walk_direction = 0;
	}
	if (keycode == 2)
	{
		data->left = 0;
		data->walk_direction = 0;
	}
	return (TRUE);
}

int	is_not_valid_xpm(t_struct *data)
{
	return (!data->xpm_ptr1 || !data->xpm_ptr2 || !data->xpm_ptr3
		|| !data->xpm_ptr4 || !data->sprite_xpm);
}
