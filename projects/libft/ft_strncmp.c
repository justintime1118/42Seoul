/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:54:03 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/19 23:30:37 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s3;
	unsigned char	*s4;
	size_t			i;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	i = 0;
	if (n <= 0)
		return (0);
	while (*s3 && *s4 && i < n)
	{
		if (*s3 != *s4)
			return ((int)(*s3 - *s4));
		s3++;
		s4++;
		i++;
	}
	if (i == n)
	{
		s3--;
		s4--;
	}
	return ((int)(*s3 - *s4));
}
