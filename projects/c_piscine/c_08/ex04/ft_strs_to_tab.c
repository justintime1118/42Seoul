/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:04:45 by jiyoo             #+#    #+#             */
/*   Updated: 2021/04/11 21:04:48 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*arr;
	int					i;
	int					length;

	arr = (struct s_stock_str *)malloc((ac + 1) * sizeof(struct s_stock_str));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		length = ft_strlen(av[i]);
		arr[i].size = length;
		arr[i].str = av[i];
		arr[i].copy = (char *)malloc((length + 1) * sizeof(char));
		if (arr[i].copy == NULL)
			return (NULL);
		arr[i].copy = ft_strcpy(arr[i].copy, av[i]);
		i++;
	}
	arr[i].str = 0;
	return (arr);
}
