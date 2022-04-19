/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_save_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:02:59 by jiyoo             #+#    #+#             */
/*   Updated: 2021/12/04 18:48:18 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_mapopen(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == 0)
		ft_puterror();
	return (fd);
}

int	ft_maplen(char **argv)
{
	int		fd;
	char	*line;
	int		ret;
	int		len;

	fd = ft_mapopen(argv);
	len = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == 0)
		{
			len++;
			free(line);
			line = 0;
			break ;
		}
		else if (ret == -1)
			ft_puterror();
		free(line);
		len++;
	}
	close(fd);
	return (len);
}

void	ft_mapsave(char **argv, int len, t_map *map_data)
{
	int	fd;
	int	i;
	int	ret;

	fd = ft_mapopen(argv);
	map_data->map_height = len;
	map_data->map = (char **)malloc(sizeof(char *) * (len + 1));
	if (map_data->map == 0)
		ft_puterror();
	map_data->map[len] = NULL;
	i = 0;
	while (map_data->map[i])
	{
		ret = get_next_line(fd, &map_data->map[i++]);
		if (ret == -1)
			exit(1);
	}
	close(fd);
}
