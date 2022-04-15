/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:50:30 by jiyoo             #+#    #+#             */
/*   Updated: 2021/12/05 18:55:33 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_levi_coord(t_map *map_data, int keycode)
{
	if (keycode == 13)
		map_data->levi_y -= 1;
	if (keycode == 0)
		map_data->levi_x -= 1;
	if (keycode == 1)
		map_data->levi_y += 1;
	if (keycode == 2)
		map_data->levi_x += 1;
}

void	ft_collectible_manage(t_map *map_data, int x, int y)
{
	map_data->map[y][x] = '0';
	if (map_data->left_key > 0)
		map_data->left_key -= 1;
}

void	ft_count_print(t_data *mlx_data, t_map *map_data)
{
	int		x;
	char	*count;
	char	*tmp;

	x = 0;
	while (x < map_data->map_width)
		ft_draw(mlx_data, x++, 0, mlx_data->wall_path);
	map_data->count += 1;
	tmp = ft_itoa(map_data->count);
	count = ft_strjoin("Steps: ", tmp);
	free(tmp);
	mlx_string_put(mlx_data->mlx, mlx_data->win, 2, 30, 0x00BB0000, count);
	free(count);
}

void	ft_escape(t_data *mlx_data)
{
	mlx_data->door_path = "./images/exit.xpm";
	ft_doordraw(mlx_data, mlx_data->map_data);
}
