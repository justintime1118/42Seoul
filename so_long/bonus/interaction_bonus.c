/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:41:18 by jiyoo             #+#    #+#             */
/*   Updated: 2021/12/05 19:21:56 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_keyhook(int keycode, t_data *mlx_data)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		ft_move(keycode, mlx_data, mlx_data->map_data);
	if (keycode == 53)
		exit(0);
	return (keycode);
}

int	ft_exit(void)
{
	exit(0);
}

void	ft_interaction(t_data *mlx_data)
{
	mlx_hook(mlx_data->win, 2, 1L << 0, ft_keyhook, mlx_data);
	mlx_hook(mlx_data->win, 17, 0, ft_exit, mlx_data);
	mlx_loop(mlx_data->mlx);
}
