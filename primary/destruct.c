/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melghoud <melghoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:16:21 by melghoud          #+#    #+#             */
/*   Updated: 2021/04/21 16:16:22 by melghoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_close(void *param)
{
	(void)param;
	exit(0);
}

int	destruct(t_struct *data)
{
	int	i;

	i = 0;
	system("killall afplay 2&>/dev/null >/dev/null");
	free(data->sprite);
	while (i < data->n_lines - 1)
	{
		free(data->map[i]);
		i++;
	}
	free(data);
	free(g_rays);
	ft_close(0);
	return (0);
}
