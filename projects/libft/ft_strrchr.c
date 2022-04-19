/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:17:55 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/19 23:30:09 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			ptr = (char *)(s + i);
			i++;
		}
		else
			i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	else
		return (ptr);
}
