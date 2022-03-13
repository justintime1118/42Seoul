/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_zero_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:14:48 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/14 10:44:27 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_i_zero_long_precision_wide(
	int precision_adder, int width_adder, t_list *flag)
{
	width_adder = flag->width - flag->precision;
	if (flag->dash)
	{
		while (precision_adder--)
			ft_putchar('0');
		while (width_adder--)
			ft_putchar(' ');
	}	
	else
	{
		while (width_adder--)
			ft_putchar(' ');
		while (precision_adder--)
			ft_putchar('0');
	}
	return (flag->width);
}

int	ft_i_zero_long_precision_narrow(int precision_adder, t_list *flag)
{
	while (precision_adder--)
		ft_putchar('0');
	return (flag->precision);
}

int	ft_i_zero_short_precision_wide(int width_adder, t_list *flag)
{
	width_adder = flag->width;
	while (width_adder--)
		ft_putchar(' ');
	return (flag->width);
}

int	ft_i_zero_precision(int char_count, t_list *flag)
{
	int	precision_adder;
	int	width_adder;

	precision_adder = flag->precision;
	width_adder = 0;
	if (flag->precision > 0)
	{
		if (flag->width > flag->precision)
			char_count = ft_i_zero_long_precision_wide(
					precision_adder, width_adder, flag);
		else
			char_count = ft_i_zero_long_precision_narrow(
					precision_adder, flag);
	}
	else
	{
		if (flag->width > 0)
			char_count = ft_i_zero_short_precision_wide(width_adder, flag);
	}
	return (char_count);
}

int	ft_i_zero_width(t_list *flag)
{
	int		width_adder;

	width_adder = flag->width - 1;
	if (flag->zero)
	{
		while (width_adder--)
			ft_putchar('0');
		ft_putchar('0');
	}
	else if (flag->dash)
	{
		ft_putchar('0');
		while (width_adder--)
			ft_putchar(' ');
	}
	else
	{
		while (width_adder--)
			ft_putchar(' ');
		ft_putchar('0');
	}
	return (flag->width);
}
