/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:19:16 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/19 23:30:26 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	ptr = (char *)malloc(i + 1);
	if (ptr == NULL)
		return (NULL);
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
