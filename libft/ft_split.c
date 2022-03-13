/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:06:23 by jiyoo             #+#    #+#             */
/*   Updated: 2021/11/10 13:51:00 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

unsigned int	get_word_cnt(char *str, char c)
{
	unsigned int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			cnt++;
			while (*str && *str != c)
				str++;
		}
	}
	return (cnt);
}

void	ft_strput(char *dst, char *from, char *until)
{
	while (from < until)
		*(dst++) = *(from++);
	*dst = 0;
}

void	ft_free(char **ret, unsigned int idx)
{
	while (idx-- > 0)
		free(ret[idx]);
	free(ret);
}

char	**ft_putwords(char *str, char c, char **ret, unsigned int idx)
{
	char	*from;

	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			from = str;
			while (*str && *str != c)
				str++;
			ret[idx] = (char *)malloc(str - from + 1);
			if (ret[idx] == 0)
			{
				ft_free(ret, idx);
				return (0);
			}
			ft_strput(ret[idx++], from, str);
		}
	}
	ret[idx] = 0;
	return (ret);
}

char			**ft_split(char *str, char c)
{
	char			**ret;
	unsigned int	idx;

	idx = 0;
	if (str == 0)
		return (0);
	ret = (char **)malloc(sizeof(char *) * (get_word_cnt(str, c) + 1));
	if (ret == 0)
		return (0);
	ft_putwords(str, c, ret, idx);
	return (ret);
}
