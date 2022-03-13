/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhan <jiwhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:47:08 by jiwhan            #+#    #+#             */
/*   Updated: 2021/04/04 22:57:56 by jiwhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		row_left(int row_idx, int col_idx);

int		row_right(int row_idx, int col_idx);

int		col_up(int row_idx, int col_idx);

int		col_down(int row_idx, int col_idx);

int		row_unique(int row_idx, int col_idx)
{
	int i;

	i = 0;
	while (i < col_idx)
	{
		if (g_map[row_idx][col_idx] == g_map[row_idx][i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		col_unique(int row_idx, int col_idx)
{
	int i;

	i = 0;
	while (i < row_idx)
	{
		if (g_map[row_idx][col_idx] == g_map[i][col_idx])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		row_check(int row_idx, int col_idx)
{
	int cnt;
	int cnt2;

	cnt = row_left(row_idx, col_idx);
	cnt2 = row_right(row_idx, col_idx);
	if (col_idx == g_size - 1)
	{
		if (cnt == g_view_num[2][row_idx] && cnt2 == g_view_num[3][row_idx])
			return (1);
	}
	else
	{
		if (cnt <= g_view_num[2][row_idx])
		{
			return (1);
		}
	}
	return (0);
}

int		col_check(int row_idx, int col_idx)
{
	int cnt;
	int cnt2;

	cnt = col_up(row_idx, col_idx);
	cnt2 = col_down(row_idx, col_idx);
	if (row_idx == g_size - 1)
	{
		if (cnt == g_view_num[0][col_idx] && cnt2 == g_view_num[1][col_idx])
			return (1);
	}
	else
	{
		if (cnt <= g_view_num[0][col_idx])
			return (1);
	}
	return (0);
}

int		map_check(int r_idx, int c_idx)
{
	if (row_unique(r_idx, c_idx) && col_unique(r_idx, c_idx))
	{
		if (row_check(r_idx, c_idx) && col_check(r_idx, c_idx))
		{
			return (1);
		}
	}
	return (0);
}
