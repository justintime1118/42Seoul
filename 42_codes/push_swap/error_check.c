/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:19:17 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/06 00:28:24 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_num_len(char **argv, int size)
{
	int		len;
	int		i;
	char	**split;

	len = 0;
	i = 0;
	while (i < size)
	{
		split = ft_split(argv[i + 1], ' ');
		len += ft_split_len(split);
		ft_free(split, ft_split_len(split));
		i++;
	}
	return (len);
}

int	ft_maxint_check(int n, char *str)
{
	if (n == 0)
	{
		while (*str)
		{
			if (*str == '0' || *str == '+' || *str == '-')
				str++;
			else
				return (0);
		}
	}
	return (1);
}

int	*ft_put_num(char **argv, int size, int *num)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	if (num == 0)
		return (0);
	i = 0;
	k = 0;
	while (i++ < size)
	{
		split = ft_split(argv[i], ' ');
		j = -1;
		while (++j < ft_split_len(split))
		{
			num[k] = ft_atoi(split[j]);
			if (ft_maxint_check(num[k++], split[j]) == 0)
			{
				ft_free(split, ft_split_len(split));
				return (0);
			}
		}
		ft_free(split, ft_split_len(split));
	}
	return (num);
}

int	*ft_error_check(char **argv, int size)
{
	int	*num;
	int	len;

	if (!ft_input_check(argv, size))
		return (0);
	len = ft_num_len(argv, size);
	num = (int *)malloc(sizeof(int) * len);
	num = ft_put_num(argv, size, num);
	if (num == 0)
		return (0);
	if (!ft_num_dupl_check(num, ft_num_len(argv, size)))
		return (0);
	return (num);
}
