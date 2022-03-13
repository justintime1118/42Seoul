/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_lower_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 17:04:40 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/14 11:26:22 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_x_lower_long_precision_wide(unsigned int x, int len, t_list *flag)
{
	int	precision_adder;
	int	width_adder;

	precision_adder = flag->precision - len;
	width_adder = flag->width - flag->precision;
	if (flag->dash)
	{
		while (precision_adder--)
			ft_putchar('0');
		ft_putnbr_x_lower(x);
		while (width_adder--)
			ft_putchar(' ');
	}	
	else
	{
		while (width_adder--)
			ft_putchar(' ');
		while (precision_adder--)
			ft_putchar('0');
		ft_putnbr_x_lower(x);
	}
	return (flag->width);
}

int	ft_x_lower_long_precision_narrow(unsigned int x, int len, t_list *flag)
{
	int	precision_adder;

	precision_adder = flag->precision - len;
	while (precision_adder--)
		ft_putchar('0');
	ft_putnbr_x_lower(x);
	return (flag->precision);
}

int	ft_x_lower_short_precision_wide(unsigned int x, int len, t_list *flag)
{
	int	width_adder;

	width_adder = flag->width - len;
	if (flag->dash)
	{
		ft_putnbr_x_lower(x);
		while (width_adder--)
			ft_putchar(' ');
	}
	else
	{
		while (width_adder--)
			ft_putchar(' ');
		ft_putnbr_x_lower(x);
	}
	return (flag->width);
}

int	ft_x_lower_precision(int char_count, unsigned int x, int len, t_list *flag)
{
	if (flag->precision > len)
	{
		if (flag->width > flag->precision)
			char_count = ft_x_lower_long_precision_wide(x, len, flag);
		else
			char_count = ft_x_lower_long_precision_narrow(
					x, len, flag);
	}
	else
	{
		if (flag->width > len)
			char_count = ft_x_lower_short_precision_wide(x, len, flag);
		else
		{
			ft_putnbr_x_lower(x);
			char_count += len;
		}
	}
	return (char_count);
}

int	ft_x_lower_width(unsigned int x, int len, t_list *flag)
{
	int	width_adder;

	width_adder = flag->width - len;
	if (flag->zero)
	{
		while (width_adder--)
			ft_putchar('0');
		ft_putnbr_x_lower(x);
	}
	else if (flag->dash)
	{
		ft_putnbr_x_lower(x);
		while (width_adder--)
			ft_putchar(' ');
	}
	else
	{
		while (width_adder--)
			ft_putchar(' ');
		ft_putnbr_x_lower(x);
	}
	return (flag->width);
}
