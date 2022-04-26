/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:00:52 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/04 17:06:35 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_split_len(char **split)
{
	int		len;

	len = 0;
	while (split[len])
		len++;
	return (len);
}

int	ft_split_check(char **split, int len, int i)
{
	int		j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (split[i][++j])
		{
			if (j == 0)
			{
				if ((split[i][j] != '-' && split[i][j] != '+') &&
				(split[i][j] < 48 || 57 < split[i][j]))
					return (0);
				if ((split[i][j] == '-' || split[i][j] == '+') &&
				!(split[i][j + 1]))
					return (0);
			}
			else
			{
				if (split[i][j] < 48 || 57 < split[i][j])
					return (0);
			}
		}
	}
	return (1);
}

int	ft_input_check(char **argv, int size)
{
	int		i;
	int		len;
	char	**split;

	i = 0;
	while (i < size)
	{
		split = ft_split(argv[i + 1], ' ');
		if (split == 0)
			return (0);
		len = ft_split_len(split);
		if (!ft_split_check(split, len, i))
		{
			ft_free(split, len);
			return (0);
		}
		ft_free(split, len);
		i++;
	}
	return (1);
}

int	ft_num_dupl_check(int *num, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (num[i] == num[j])
			{
				free(num);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_input_sort_check(int *num, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (num[i] < num[i + 1])
			i++;
		else
			break ;
	}
	if (i == len - 1)
		return (0);
	else
		return (1);
}
