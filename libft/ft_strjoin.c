/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:20:51 by jiyoo             #+#    #+#             */
/*   Updated: 2021/11/10 13:50:27 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*ptr;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	len = i + j;
	ptr = (char *)malloc(len + 1);
	if (ptr == 0)
		return (0);
	ptr[i + j] = '\0';
	while (j--)
		ptr[i + j] = s2[j];
	while (i--)
		ptr[i] = s1[i];
	return (ptr);
}
