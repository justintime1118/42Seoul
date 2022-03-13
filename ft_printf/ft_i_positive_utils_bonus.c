/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:49:02 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/05 16:04:37 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_i_posi_long_precision_wide(int d, int len, t_list *flag)
{
	int	precision_adder;
	int	width_adder;

	precision_adder = flag->precision - len;
	width_adder = flag->width - flag->precision;
	if (flag->dash)
	{
		while (precision_adder--)
			ft_putchar('0');
		ft_putnbr_i(d);
		while (width_adder--)
			ft_putchar(' ');
	}	
	else
	{
		while (width_adder--)
			ft_putchar(' ');
		while (precision_adder--)
			ft_putchar('0');
		ft_putnbr_i(d);
	}
	return (flag->width);
}

int	ft_i_posi_long_precision_narrow(int d, int len, t_list *flag)
{
	int	precision_adder;

	precision_adder = flag->precision - len;
	while (precision_adder--)
		ft_putchar('0');
	ft_putnbr_i(d);
	return (flag->precision);
}

int	ft_i_posi_short_precision_wide(int d, int len, t_list *flag)
{
	int	width_adder;

	width_adder = flag->width - len;
	if (flag->dash)
	{
		ft_putnbr_i(d);
		while (width_adder--)
			ft_putchar(' ');
	}
	else
	{
		while (width_adder--)
			ft_putchar(' ');
		ft_putnbr_i(d);
	}
	return (flag->width);
}

int	ft_i_posi_precision(int char_count, int d, int len, t_list *flag)
{
	if (flag->precision > len)
	{
		if (flag->width > flag->precision)
			char_count = ft_i_posi_long_precision_wide(d, len, flag);
		else
			char_count = ft_i_posi_long_precision_narrow(d, len, flag);
	}
	else
	{
		if (flag->width > len)
			char_count = ft_i_posi_short_precision_wide(d, len, flag);
		else
		{
			ft_putnbr_i(d);
			char_count += len;
		}
	}
	return (char_count);
}

int	ft_i_posi_width(int d, int len, t_list *flag)
{
	int	width_adder;

	width_adder = flag->width - len;
	if (flag->zero)
	{
		while (width_adder--)
			ft_putchar('0');
		ft_putnbr_i(d);
	}
	else if (flag->dash)
	{
		ft_putnbr_i(d);
		while (width_adder--)
			ft_putchar(' ');
	}
	else
	{
		while (width_adder--)
			ft_putchar(' ');
		ft_putnbr_i(d);
	}
	return (flag->width);
}
