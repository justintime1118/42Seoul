/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:20:23 by jiyoo             #+#    #+#             */
/*   Updated: 2021/05/21 18:47:41 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*char_dst;
	const char	*char_src;

	char_dst = dst;
	char_src = src;
	if (dst == src)
		return (dst);
	i = 0;
	if (src > dst)
	{
		while (i < len)
		{
			char_dst[i] = char_src[i];
			i++;
		}
	}
	else
	{
		while (len--)
		{
			char_dst[len] = char_src[len];
		}
	}
	return (dst);
}
