/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:27:24 by jiyoo             #+#    #+#             */
/*   Updated: 2021/11/10 13:49:59 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	long long	len;
	char		*ptr;

	len = 0;
	while (s1[len])
		len++;
	ptr = (char *)malloc(len + 1);
	if (ptr == 0)
		return (0);
	ptr[len] = 0;
	while (--len >= 0)
		ptr[len] = s1[len];
	return (ptr);
}
