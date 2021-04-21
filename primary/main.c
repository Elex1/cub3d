/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melghoud <melghoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:51:34 by melghoud          #+#    #+#             */
/*   Updated: 2021/04/21 16:53:40 by melghoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	update(t_struct *data)
{
	cast_rays(data);
	render_walls(data);
	move_player(data);
	if (data->g_screenshott)
	{
		screen(data);
		destruct(data);
		ft_close(data);
	}
	if (data->reset)
		init_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img_ptr, 0, 0);
	return (FALSE);
}

int	initialize_window(t_struct *data)
{
	set_up_data(data);
	if (!(set_up_window(data)))
		return (FALSE);
	texture_from_file(data);
	mlx_hook(data->win_ptr, 3, 0, key_released, data);
	mlx_hook(data->win_ptr, 2, 0, key_pressed, data);
	mlx_hook(data->win_ptr, 17, 0L, destruct, data);
	mlx_loop_hook(data->mlx_ptr, update, data);
	mlx_loop(data->mlx_ptr);
	return (TRUE);
}

int	are_valid_args(int ac, char **av, int g_screenshot)
{
	size_t	av_len;

	if (av[1] != NULL)
		av_len = ft_strlen(av[1]) - 1;
	if (ac < 2)
		error("\e[0;31m No map included!\n");
	else if (ac >= 2 && av[1][av_len] == 'b' && av[1][av_len - 1] == 'u'
			&& ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
	{
		if (ac == 2)
			return (TRUE);
		if (ac == 3 && ft_strlen(av[2]) == 6
			&& !ft_strncmp(av[2], "--save", ft_strlen(av[2])))
		{
			g_screenshot = TRUE;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	main(int ac, char *av[])
{
	t_struct	*data;
	int			g_screenshot;

	g_screenshot = 0;
	if (!are_valid_args(ac, av, g_screenshot))
		error("\e[0;31m args are not valid\n");
	data = malloc(sizeof(t_struct));
	data->g_screenshott = g_screenshot;
	if (!parse(data, av))
		return (1);
	g_rays = (t_ray *)malloc(sizeof(t_ray) * data->w_width);
	if (!initialize_window(data))
		return (TRUE);
	free(data);
	return (FALSE);
}
