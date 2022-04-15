/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhan <jiwhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:47:21 by jiwhan            #+#    #+#             */
/*   Updated: 2021/04/04 22:58:09 by jiwhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush01.h"

void	create_map(int size);

void	print_map(void);

void	dynamic_allocation(int x_size, int y_size)
{
	int i;

	i = 0;
	g_view_num = (int **)malloc(8 * x_size);
	while (i < 4)
	{
		g_view_num[i] = (int *)malloc(4 * y_size);
		i++;
	}
}

int		cnt_num_from_str(char *str_num)
{
	int cnt;
	int i;

	i = 0;
	cnt = 0;
	while (str_num[i])
	{
		if (i % 2 == 0)
		{
			if (str_num[i] >= '1' && str_num[i] <= '9')
				cnt++;
			else
				return (0);
		}
		else
		{
			if (str_num[i] != ' ')
				return (0);
		}
		i++;
	}
	if (cnt % 4 != 0)
		return (0);
	return (cnt);
}

int		extract_number_arr(char *str_num)
{
	int i;
	int j;

	g_size = cnt_num_from_str(str_num) / 4;
	if (g_size == 0)
		return (0);
	dynamic_allocation(4, g_size);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < (g_size))
		{
			if (*str_num >= '1' && *str_num <= g_size + '0')
			{
				g_view_num[i][j] = *str_num - '0';
				j++;
			}
			else if (*str_num != ' ')
				return (0);
			str_num++;
		}
		i++;
	}
	return (1);
}

int		check_range(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < g_size)
		{
			if (g_view_num[i][j] > g_size)
				return (0);
		}
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	int i;

	if (argc != 2 || extract_number_arr(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	create_map(g_size);
	i = 0;
	while (i < g_size)
	{
		free(g_map[i]);
		i++;
	}
	free(g_map);
	while (i < 4)
	{
		free(g_view_num[i]);
		i++;
	}
	free(g_view_num);
	return (0);
}
