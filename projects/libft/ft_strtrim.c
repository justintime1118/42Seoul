/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:42:31 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/19 23:30:30 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cnt_head(char const *s1, char const *set, int cnt)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	while (s1[i++])
		cnt++;
	return (cnt);
}

int	ft_cnt_tail(char const *s1, char const *set, int cnt)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s1[i])
		i++;
	i -= 1;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			cnt--;
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (cnt);
}

int	ft_cnt(char const *s1, char const *set)
{
	int		cnt;

	cnt = 0;
	cnt = ft_cnt_head(s1, set, cnt);
	if (cnt == 0)
		return (cnt);
	cnt = ft_cnt_tail(s1, set, cnt);
	return (cnt);
}

char	*ft_trim(char const *s1, char const *set, int len, char *ptr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	j = 0;
	while (len--)
		ptr[j++] = s1[i++];
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		len;

	if (s1 == 0)
		return (0);
	len = ft_cnt(s1, set);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	return (ft_trim(s1, set, len, ptr));
}
