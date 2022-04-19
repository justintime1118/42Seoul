/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:38:13 by jiyoo             #+#    #+#             */
/*   Updated: 2021/11/20 13:41:29 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	long long	len;
	char		*ret;

	if (src == 0 || *src == 0)
		exit(1);
	len = ft_strlen(src);
	ret = (char *)malloc(len + 1);
	if (ret == 0)
	{
		perror("memory allocation error");
		exit(1);
	}
	ret[len] = 0;
	while (--len >= 0)
		ret[len] = src[len];
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*ptr;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (s1 == 0 || s2 == 0)
		return (0);
	len = i + j;
	ptr = (char *)malloc(len + 1);
	if (ptr == 0)
	{
		perror("memory allocation error");
		exit(1);
	}
	ptr[i + j] = '\0';
	while (j--)
		ptr[i + j] = s2[j];
	while (i--)
		ptr[i] = s1[i];
	return (ptr);
}
