/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:26:43 by jiyoo             #+#    #+#             */
/*   Updated: 2021/05/21 19:03:07 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*a;
	char	*b;
	size_t	left_len;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		left_len = len;
		a = (char *)haystack;
		b = (char *)needle;
		while (*b && *a == *b && left_len)
		{
			a++;
			b++;
			left_len--;
		}
		if (*b == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
