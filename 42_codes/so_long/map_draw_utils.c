/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:37:10 by jiyoo             #+#    #+#             */
/*   Updated: 2021/12/05 19:12:18 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw(t_data *mlx_data, int x, int y, char *path)
{
	mlx_data->img = mlx_xpm_file_to_image(mlx_data->mlx, path,
			&mlx_data->img_width, &mlx_data->img_height);
	if (mlx_data->img == 0)
		ft_puterror();
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
		mlx_data->img, 60 * x, 60 * y);
}

void	ft_doordraw(t_data *mlx_data, t_map *map_data)
{
	int	x;
	int	y;

	x = 0;
	while (x < map_data->map_width)
	{
		y = 0;
		while (y < map_data->map_height)
		{
			if (map_data->map[y][x] == 'E')
				break ;
			y++;
		}
		if (y < map_data->map_height && map_data->map[y][x] == 'E')
			break ;
		x++;
	}
	mlx_data->img = mlx_xpm_file_to_image(mlx_data->mlx, mlx_data->door_path,
			&mlx_data->img_width, &mlx_data->img_height);
	if (mlx_data->img == 0)
		ft_puterror();
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
		mlx_data->img, 60 * x, 60 * y);
}

void	ft_movedraw(t_data *mlx_data, t_map *map_data, int x, int y)
{
	ft_draw(mlx_data, x, y, mlx_data->tile_path);
	if (map_data->map[y][x] == 'E')
		ft_draw(mlx_data, x, y, mlx_data->door_path);
	if (map_data->map[map_data->levi_y][map_data->levi_x] != 'E')
		ft_draw(mlx_data, map_data->levi_x, map_data->levi_y,
			mlx_data->tile_path);
	ft_draw(mlx_data, map_data->levi_x, map_data->levi_y, mlx_data->levi_path);
}

void	ft_ending_draw(t_data *mlx_data, t_map *map_data)
{
	mlx_data->img = mlx_xpm_file_to_image(mlx_data->mlx, "./images/ending.xpm",
			&mlx_data->img_width, &mlx_data->img_height);
	if (mlx_data->img == 0)
		ft_puterror();
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
		mlx_data->img, (map_data->map_width * 60 - mlx_data->img_width) / 2,
		(map_data->map_height * 60 - mlx_data->img_height) / 2);
}
