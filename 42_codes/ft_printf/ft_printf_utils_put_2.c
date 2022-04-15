/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_put_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:49:32 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/13 18:22:02 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_x_upper(unsigned long n)
{
	if (n > 15)
		ft_putnbr_x_upper(n / 16);
	if (0 <= (n % 16) && (n % 16) <= 9)
		ft_putchar(48 + (n % 16));
	else
		ft_putchar(55 + (n % 16));
}

void	ft_putnbr_p(unsigned long p)
{
	if (p > 15)
		ft_putnbr_p(p / 16);
	if (0 <= (p % 16) && (p % 16) <= 9)
		ft_putchar(48 + (p % 16));
	else
		ft_putchar(87 + (p % 16));
}
