/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:39:45 by jiyoo             #+#    #+#             */
/*   Updated: 2021/05/11 15:52:51 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		get_len(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len += 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	putnbr(int n, char *ptr, int len)
{
	ptr[len--] = '\0';
	if (n == 0)
		ptr[0] = '0';
	if (n == -2147483648)
	{
		ptr[10] = '8';
		len -= 1;
		n /= 10;
	}
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	while (n)
	{
		ptr[len--] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	len = get_len(n);
	if (!(ptr = (char *)malloc(len + 1)))
		return (0);
	putnbr(n, ptr, len);
	return (ptr);
}
