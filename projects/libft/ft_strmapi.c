/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:17:28 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/19 23:30:19 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*ptr;
	unsigned int	i;

	i = 0;
	if (s == 0)
		return (0);
	len = ft_strlen(s);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}
