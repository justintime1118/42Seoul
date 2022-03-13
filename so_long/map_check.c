/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:50:25 by jiyoo             #+#    #+#             */
/*   Updated: 2022/01/14 11:13:37 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_width_check(t_map *map_data)
{
	int	i;
	int	width;

	width = ft_strlen(map_data->map[0]);
	i = 1;
	while (map_data->map[i])
	{
		if (width > 2 && width == ft_strlen(map_data->map[i]))
			i++;
		else
			break ;
	}
	if (i == map_data->map_height)
	{
		map_data->map_width = width;
		return (0);
	}
	else
		return (-1);
}

int	ft_map_wall_check(t_map *map_data)
{
	int	i;

	i = 0;
	while (map_data->map[0][i] && map_data->map[0][i] == '1'
		 && map_data->map[map_data->map_height - 1][i] == '1')
		i++;
	if (i != map_data->map_width)
		return (-1);
	i = 0;
	while (map_data->map[i] && map_data->map[i][0] == '1'
		 && map_data->map[i][map_data->map_width - 1] == '1')
		i++;
	if (i != map_data->map_height)
		return (-1);
	return (0);
}

int	ft_map_element_check(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (map_data->map[i])
	{
		j = 0;
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] != 'P' && map_data->map[i][j] != 'E'
				&& map_data->map[i][j] != 'C' && map_data->map[i][j] != '0'
				&& map_data->map[i][j] != '1')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_map_validity_check(t_map *map_data, int p, int e, int c)
{
	int	i;
	int	j;

	i = 0;
	while (map_data->map[i])
	{
		j = 0;
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == 'P')
				p++;
			if (map_data->map[i][j] == 'E')
				e++;
			if (map_data->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (p != 1 || e == 0 || c == 0)
		return (-1);
	else
		return (0);
}

void	ft_mapcheck(t_map *map_data)
{
	if (ft_map_width_check(map_data) == -1 || ft_map_wall_check(map_data) == -1
		|| ft_map_element_check(map_data)
		|| ft_map_validity_check(map_data, 0, 0, 0) == -1)
	{
		write(1, "Error\n", 6);
		write(1, "Map error\n", 10);
		exit(1);
	}
}
