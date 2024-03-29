/* ************************************************************************************************ */
/*                                                                                                  */
/*                                                        :::   ::::::::   ::::::::  :::::::::::    */
/*   utils2.c                                          :+:+:  :+:    :+: :+:    :+: :+:     :+:     */
/*                                                      +:+         +:+        +:+        +:+       */
/*   By: melghoud <melghoud@student.1337.ma>           +#+      +#++:      +#++:        +#+         */
/*                                                    +#+         +#+        +#+      +#+           */
/*   Created: 2021/04/21 14:06:22 by melghoud        #+#  #+#    #+# #+#    #+#     #+#             */
/*   Updated: 2021/04/21 14:06:22 by melghoud     ####### ########   ########      ###.ma           */
/*                                                                                                  */
/* ************************************************************************************************ */

#include "../include/cub3d.h"

int		skip_number(const char *str)
{
	int i;

	i = 0;
	if (str[i] == ',' || str[i] == ' ')
		i++;
	while ((str[i] >= 48 && str[i] <= 57) && (str[i] != ' ' || str[i] != ','))
		i++;
	return (i);
}

void	error(char *str)
{
	write(1, str, ft_strlen(str));
	system("killall afplay 2&>/dev/null >/dev/null");
	exit(EXIT_FAILURE);
}

int		is_valid_color(const t_struct *data, int id)
{
	return (data->sprite_tex_data[id] != data->sprite_tex_data[0]);
}

int		int_len(int x)
{
	if (x >= 1000000000)
		return (10);
	if (x >= 100000000)
		return (9);
	if (x >= 10000000)
		return (8);
	if (x >= 1000000)
		return (7);
	if (x >= 100000)
		return (6);
	if (x >= 10000)
		return (5);
	if (x >= 1000)
		return (4);
	if (x >= 100)
		return (3);
	if (x >= 10)
		return (2);
	return (1);
}