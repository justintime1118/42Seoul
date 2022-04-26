/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 11:36:04 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/13 18:42:15 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	write(1, s, len);
}

void	ft_putnbr_i(int n)
{
	if (n == -2147483648)
	{
		ft_putnbr_i(n / 10);
		ft_putchar('8');
	}
	else if (n < 0)
		ft_putnbr_i(-n);
	else
	{
		if (n > 9)
		{
			ft_putnbr_i(n / 10);
		}
		ft_putchar(48 + (n % 10));
	}
}

void	ft_putnbr_u(unsigned int n)
{
	if (n > 9)
		ft_putnbr_u(n / 10);
	ft_putchar(48 + (n % 10));
}

void	ft_putnbr_x_lower(unsigned long n)
{
	if (n > 15)
		ft_putnbr_x_lower(n / 16);
	if (0 <= (n % 16) && (n % 16) <= 9)
		ft_putchar(48 + (n % 16));
	else
		ft_putchar(87 + (n % 16));
}
