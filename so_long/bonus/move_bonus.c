/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:48:13 by jiyoo             #+#    #+#             */
/*   Updated: 2021/12/05 19:24:43 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_up(t_data *mlx_data, t_map *map_data, int x, int y)
{
	int	keycode;

	keycode = 13;
	if (map_data->map[y - 1][x] == '1')
		return ;
	if (mlx_data->levi_path[14] == 's' && mlx_data->levi_path[16] == 'r')
		mlx_data->levi_path = "./images/levi_d_r.xpm";
	else if (mlx_data->levi_path[14] == 's' && mlx_data->levi_path[16] == 'l')
		mlx_data->levi_path = "./images/levi_d_l.xpm";
	else if (mlx_data->levi_path[14] == 'd' && mlx_data->levi_path[16] == 'r')
		mlx_data->levi_path = "./images/levi_s_r.xpm";
	else
		mlx_data->levi_path = "./images/levi_s_l.xpm";
	ft_levi_coord(map_data, keycode);
	ft_movedraw(mlx_data, map_data, x, y);
	if (map_data->map[y - 1][x] == 'C')
		ft_collectible_manage(map_data, x, y - 1);
	else if (map_data->map[y - 1][x] == 'E' && map_data->left_key == 0)
		ft_escape(mlx_data);
}

void	ft_move_left(t_data *mlx_data, t_map *map_data, int x, int y)
{
	int	keycode;

	keycode = 0;
	if (map_data->map[y][x - 1] == '1')
		return ;
	if (mlx_data->levi_path[14] == 's' && mlx_data->levi_path[16] == 'r')
		mlx_data->levi_path = "./images/levi_d_l.xpm";
	else if (mlx_data->levi_path[14] == 'd' && mlx_data->levi_path[16] == 'r')
		mlx_data->levi_path = "./images/levi_s_l.xpm";
	else if (mlx_data->levi_path[14] == 's' && mlx_data->levi_path[16] == 'l')
		mlx_data->levi_path = "./images/levi_d_l.xpm";
	else
		mlx_data->levi_path = "./images/levi_s_l.xpm";
	ft_levi_coord(map_data, keycode);
	ft_movedraw(mlx_data, map_data, x, y);
	if (map_data->map[y][x - 1] == 'C')
		ft_collectible_manage(map_data, x - 1, y);
	else if (map_data->map[y][x - 1] == 'E' && map_data->left_key == 0)
		ft_escape(mlx_data);
}

void	ft_move_down(t_data *mlx_data, t_map *map_data, int x, int y)
{
	int	keycode;

	keycode = 1;
	if (map_data->map[y + 1][x] == '1')
		return ;
	if (mlx_data->levi_path[14] == 's' && mlx_data->levi_path[16] == 'r')
		mlx_data->levi_path = "./images/levi_d_r.xpm";
	else if (mlx_data->levi_path[14] == 's' && mlx_data->levi_path[16] == 'l')
		mlx_data->levi_path = "./images/levi_d_l.xpm";
	else if (mlx_data->levi_path[14] == 'd' && mlx_data->levi_path[16] == 'r')
		mlx_data->levi_path = "./images/levi_s_r.xpm";
	else
		mlx_data->levi_path = "./images/levi_s_l.xpm";
	ft_levi_coord(map_data, keycode);
	ft_movedraw(mlx_data, map_data, x, y);
	if (map_data->map[y + 1][x] == 'C')
		ft_collectible_manage(map_data, x, y + 1);
	else if (map_data->map[y + 1][x] == 'E' && map_data->left_key == 0)
		ft_escape(mlx_data);
}

void	ft_move_right(t_data *mlx_data, t_map *map_data, int x, int y)
{
	int	keycode;

	keycode = 2;
	if (map_data->map[y][x + 1] == '1')
		return ;
	if (mlx_data->levi_path[14] == 's' && mlx_data->levi_path[16] == 'l')
		mlx_data->levi_path = "./images/levi_d_r.xpm";
	else if (mlx_data->levi_path[14] == 'd' && mlx_data->levi_path[16] == 'l')
		mlx_data->levi_path = "./images/levi_s_r.xpm";
	else if (mlx_data->levi_path[14] == 's' && mlx_data->levi_path[16] == 'r')
		mlx_data->levi_path = "./images/levi_d_r.xpm";
	else
		mlx_data->levi_path = "./images/levi_s_r.xpm";
	ft_levi_coord(map_data, keycode);
	ft_movedraw(mlx_data, map_data, x, y);
	if (map_data->map[y][x + 1] == 'C')
		ft_collectible_manage(map_data, x + 1, y);
	else if (map_data->map[y][x + 1] == 'E' && map_data->left_key == 0)
		ft_escape(mlx_data);
}

void	ft_move(int keycode, t_data *mlx_data, t_map *map_data)
{
	if (map_data->left_key == 0
		&& map_data->map[map_data->levi_y][map_data->levi_x] == 'E')
	{
		ft_ending_draw(mlx_data, map_data);
		return ;
	}
	if (keycode == 13 || keycode == 0
		|| keycode == 1 || keycode == 2)
		ft_count_print(mlx_data, map_data);
	if (keycode == 13)
		ft_move_up(mlx_data, map_data, map_data->levi_x, map_data->levi_y);
	if (keycode == 0)
		ft_move_left(mlx_data, map_data, map_data->levi_x, map_data->levi_y);
	if (keycode == 1)
		ft_move_down(mlx_data, map_data, map_data->levi_x, map_data->levi_y);
	if (keycode == 2)
		ft_move_right(mlx_data, map_data, map_data->levi_x, map_data->levi_y);
}
