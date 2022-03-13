/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhan <jiwhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 01:43:38 by jiwhan            #+#    #+#             */
/*   Updated: 2021/04/04 22:57:59 by jiwhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush01.h"

int g_check = 0;

int		map_check(int r_idx, int c_idx);

void	allocate_map(void)
{
	int i;

	i = 0;
	g_map = (int **)malloc(8 * g_size);
	while (i < g_size)
	{
		g_map[i] = (int *)malloc(4 * g_size);
		i++;
	}
}

void	print_map(void)
{
	int		i;
	int		j;
	char	num;

	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			num = g_map[i][j] + '0';
			write(1, &num, 1);
			if (j == g_size - 1)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			j++;
		}
		i++;
	}
	g_check = 1;
}

void	input_map(int r_idx, int c_idx)
{
	int cnt;

	if (r_idx == g_size)
	{
		print_map();
		return ;
	}
	cnt = 1;
	while (cnt++ <= g_size)
	{
		g_map[r_idx][c_idx] = cnt - 1;
		if (map_check(r_idx, c_idx))
		{
			if (c_idx == g_size - 1)
				input_map(r_idx + 1, 0);
			else
				input_map(r_idx, c_idx + 1);
		}
	}
	if (r_idx == 0 && c_idx == 0 && cnt - 1 == g_size + 1)
	{
		if (g_check == 0)
			write(1, "Error\n", 6);
		return ;
	}
}

void	create_map(void)
{
	allocate_map();
	input_map(0, 0);
}
