/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_col_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwhan <jiwhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 21:47:24 by jiwhan            #+#    #+#             */
/*   Updated: 2021/04/04 22:51:18 by jiwhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		row_left(int row_idx, int col_idx)
{
	int cnt;
	int k;
	int max;

	cnt = 0;
	k = 0;
	max = 0;
	while (k <= col_idx)
	{
		if (max < g_map[row_idx][k])
		{
			max = g_map[row_idx][k];
			cnt++;
		}
		k++;
	}
	return (cnt);
}

int		row_right(int row_idx, int col_idx)
{
	int cnt;
	int k;
	int max;

	cnt = 0;
	k = col_idx;
	max = 0;
	while (k >= 0)
	{
		if (max < g_map[row_idx][k])
		{
			max = g_map[row_idx][k];
			cnt++;
		}
		k--;
	}
	return (cnt);
}

int		col_up(int row_idx, int col_idx)
{
	int cnt;
	int k;
	int max;

	cnt = 0;
	k = 0;
	max = 0;
	while (k <= row_idx)
	{
		if (max < g_map[k][col_idx])
		{
			max = g_map[k][col_idx];
			cnt++;
		}
		k++;
	}
	return (cnt);
}

int		col_down(int row_idx, int col_idx)
{
	int max;
	int cnt;
	int k;

	cnt = 0;
	k = row_idx;
	max = 0;
	while (k >= 0)
	{
		if (max < g_map[k][col_idx])
		{
			max = g_map[k][col_idx];
			cnt++;
		}
		k--;
	}
	return (cnt);
}
