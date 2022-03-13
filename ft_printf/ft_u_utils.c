/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:08:00 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/14 18:39:52 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u_long_precision_wide(unsigned int u,
		int precision_adder, int width_adder, t_list *flag)
{
	width_adder = flag->width - flag->precision;
	if (flag->dash)
	{
		while (precision_adder--)
			ft_putchar('0');
		ft_putnbr_u(u);
		while (width_adder--)
			ft_putchar(' ');
	}	
	else
	{
		while (width_adder--)
			ft_putchar(' ');
		while (precision_adder--)
			ft_putchar('0');
		ft_putnbr_u(u);
	}
	return (flag->width);
}

int	ft_u_long_precision_narrow(
		unsigned int u, int precision_adder, t_list *flag)
{
	while (precision_adder--)
		ft_putchar('0');
	ft_putnbr_u(u);
	return (flag->precision);
}

int	ft_u_short_precision_wide(unsigned int u,
		int width_adder, int len, t_list *flag)
{
	width_adder = flag->width - len;
	if (flag->dash)
	{
		ft_putnbr_u(u);
		while (width_adder--)
			ft_putchar(' ');
	}
	else
	{
		while (width_adder--)
			ft_putchar(' ');
		ft_putnbr_u(u);
	}
	return (flag->width);
}

int	ft_u_precision(int char_count, unsigned int u, int len, t_list *flag)
{
	int		precision_adder;
	int		width_adder;

	precision_adder = flag->precision - len;
	width_adder = 0;
	if (flag->precision > len)
	{
		if (flag->width > flag->precision)
			char_count = ft_u_long_precision_wide(u,
					precision_adder, width_adder, flag);
		else
			char_count = ft_u_long_precision_narrow(
					u, precision_adder, flag);
	}
	else
	{
		if (flag->width > len)
			char_count = ft_u_short_precision_wide(u, width_adder, len, flag);
		else
		{
			ft_putnbr_u(u);
			char_count += len;
		}
	}
	return (char_count);
}

int	ft_u_width(unsigned int u, int len, t_list *flag)
{
	int	width_adder;

	width_adder = flag->width - len;
	if (flag->zero)
	{
		while (width_adder--)
			ft_putchar('0');
		ft_putnbr_u(u);
	}
	else if (flag->dash)
	{
		ft_putnbr_u(u);
		while (width_adder--)
			ft_putchar(' ');
	}
	else
	{
		while (width_adder--)
			ft_putchar(' ');
		ft_putnbr_u(u);
	}
	return (flag->width);
}
