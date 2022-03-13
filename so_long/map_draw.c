/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:28:10 by jiyoo             #+#    #+#             */
/*   Updated: 2021/12/05 19:20:04 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapinit(t_map *map_data, t_data *mlx_data)
{
	mlx_data->map_data = map_data;
	mlx_data->mlx = mlx_init();
	if (mlx_data->mlx == 0)
		ft_puterror();
	mlx_data->win = mlx_new_window(mlx_data->mlx, 60 * map_data->map_width,
			60 * map_data->map_height, "Attack On Titan - Levi Ackerman");
	if (mlx_data->win == 0)
		ft_puterror();
	map_data->count = 0;
	map_data->left_key = 0;
	mlx_data->tile_path = "./images/tile.xpm";
	mlx_data->wall_path = "./images/wall.xpm";
	mlx_data->levi_path = "./images/levi_s_r.xpm";
	mlx_data->key_path = "./images/key.xpm";
	mlx_data->door_path = "./images/door.xpm";
}

void	ft_mapdraw(t_map *map_data, t_data *mlx_data, int x, int y)
{
	ft_mapinit(map_data, mlx_data);
	while (x < map_data->map_width)
	{
		y = 0;
		while (y < map_data->map_height)
		{
			ft_draw(mlx_data, x, y, mlx_data->tile_path);
			if (map_data->map[y][x] == '1')
				ft_draw(mlx_data, x, y, mlx_data->wall_path);
			if (map_data->map[y][x] == 'P')
			{
				map_data->levi_x = x;
				map_data->levi_y = y;
				map_data->map[y][x] = '0';
				ft_draw(mlx_data, x, y, mlx_data->levi_path);
			}
			if (map_data->map[y][x] == 'C')
			{
				map_data->left_key += 1;
				ft_draw(mlx_data, x, y, mlx_data->key_path);
			}
			y++;
		}
		x++;
	}
}
