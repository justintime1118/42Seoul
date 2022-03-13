/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:33:30 by jiyoo             #+#    #+#             */
/*   Updated: 2021/12/04 18:48:48 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	if (dst == 0 || src == 0)
		return (0);
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = (char *)malloc(i + j + 1);
	if (ptr == 0)
		return (NULL);
	ptr[i + j] = '\0';
	while (j--)
		ptr[i + j] = s2[j];
	while (i--)
		ptr[i] = s1[i];
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	long long	len;
	char		*ptr;

	len = ft_strlen(s1);
	ptr = (char *)malloc(len + 1);
	if (ptr == 0)
		return (NULL);
	ptr[len] = '\0';
	ft_strlcpy(ptr, s1, len + 1);
	return (ptr);
}

void	ft_puterror(void)
{
	perror("Error\n");
	exit(1);
}
