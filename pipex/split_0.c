/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:23:06 by jiyoo             #+#    #+#             */
/*   Updated: 2021/11/16 04:30:31 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_word_cnt(char *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			cnt++;
			if (*str++ == '\'')
			{
				while (*str && *str != '\'')
					str++;
				if (*str == '\'')
					str++;
			}
			else
			{
				while (*str && *str != c)
					str++;
			}
		}
	}
	return (cnt);
}

char	*ft_putwords_quote(char *str, char **ret, int idx)
{
	char	*from;

	from = str;
	while (*str && *str != '\'')
		str++;
	ret[idx] = (char *)malloc(str - from + 1);
	if (ret[idx] == 0)
	{
		perror("memory allocation error");
		exit(1);
	}
	ft_strput(ret[idx], from, str);
	return (str);
}

char	*ft_putwords_c(char *str, char **ret, char c, int idx)
{
	char	*from;

	from = str;
	while (*str && *str != c)
		str++;
	ret[idx] = (char *)malloc(str - from + 1);
	if (ret[idx] == 0)
	{
		perror("memory allocation error");
		exit(1);
	}
	ft_strput(ret[idx], from, str);
	return (str);
}

char	**ft_putwords(char *str, char c, char **ret)
{
	int		idx;

	idx = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			if (*str == '\'')
			{
				str++;
				str = ft_putwords_quote(str, ret, idx);
				idx++;
			}
			else
			{
				str = ft_putwords_c(str, ret, c, idx);
				idx++;
			}
		}
	}
	ret[idx] = 0;
	return (ret);
}

char	**ft_split(char *str, char c)
{
	char	**ret;

	ft_split_check(str);
	ret = (char **)malloc(sizeof(char *) * (get_word_cnt(str, c) + 1));
	if (ret == 0)
	{
		perror("memory allocation error");
		exit(1);
	}
	ret = ft_putwords(str, c, ret);
	return (ret);
}
