/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:19:16 by jiyoo             #+#    #+#             */
/*   Updated: 2021/05/26 20:02:58 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	length_of_s;

	length_of_s = 0;
	if (s == 0)
		return (0);
	while (*(s + length_of_s))
		length_of_s++;
	i = 0;
	while (s[start + i] && i < len)
		i++;
	if (!(ptr = (char *)malloc(i + 1)))
		return (0);
	if (start > length_of_s)
	{
		ptr[0] = '\0';
		return (ptr);
	}
	ptr[i] = '\0';
	while (i--)
		ptr[i] = s[start + i];
	return (ptr);
}
