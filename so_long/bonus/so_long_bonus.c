/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:07:17 by jiyoo             #+#    #+#             */
/*   Updated: 2021/12/05 19:27:34 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	mlx_data;
	t_map	map_data;

	if (argc != 2)
		exit(1);
	ft_mapsave(argv, ft_maplen(argv), &map_data);
	ft_mapcheck(&map_data);
	ft_mapdraw(&map_data, &mlx_data, 0, 0);
	ft_doordraw(&mlx_data, &map_data);
	ft_interaction(&mlx_data);
}
