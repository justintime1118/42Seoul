/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:26:12 by jiyoo             #+#    #+#             */
/*   Updated: 2021/05/25 16:43:39 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	char	*ret;
	size_t	cnt;

	if (!(ptr = malloc(count * size)))
		return (0);
	ret = ptr;
	cnt = count * size;
	while (cnt--)
	{
		*ptr = 0;
		ptr++;
	}
	return (ret);
}
