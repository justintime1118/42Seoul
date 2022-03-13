/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:39:45 by jiyoo             #+#    #+#             */
/*   Updated: 2021/12/02 19:33:54 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_numlen(int n)
{
	int	len;

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

void	ft_putnbr(int n, char *ptr, int len)
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

	len = ft_numlen(n);
	ptr = (char *)malloc(len + 1);
	if (ptr == 0)
		return (0);
	ft_putnbr(n, ptr, len);
	return (ptr);
}
