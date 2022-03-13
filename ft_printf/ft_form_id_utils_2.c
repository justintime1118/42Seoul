/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_id_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:55:02 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/14 10:58:31 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x_lower_processor(t_list *flag, va_list ap)
{
	int				char_count;
	unsigned int	x;
	int				len;

	char_count = 0;
	x = va_arg(ap, unsigned int);
	len = ft_nbr_len_x(x);
	if (x == 0)
		char_count = ft_i_zero(char_count, flag);
	else if (flag->precision > 0)
		char_count = ft_x_lower_precision(char_count, x, len, flag);
	else if (flag->width > len)
		char_count = ft_x_lower_width(x, len, flag);
	else
	{
		ft_putnbr_x_lower(x);
		char_count += len;
	}
	return (char_count);
}

int	ft_x_upper_processor(t_list *flag, va_list ap)
{
	int				char_count;
	unsigned int	x;
	int				len;

	char_count = 0;
	x = va_arg(ap, unsigned int);
	len = ft_nbr_len_x(x);
	if (x == 0)
		char_count = ft_i_zero(char_count, flag);
	else if (flag->precision > 0)
		char_count = ft_x_upper_precision(char_count, x, len, flag);
	else if (flag->width > len)
		char_count = ft_x_upper_width(x, len, flag);
	else
	{
		ft_putnbr_x_upper(x);
		char_count += len;
	}
	return (char_count);
}

int	ft_p_processor(t_list *flag, va_list ap)
{
	int				char_count;
	unsigned long	p;
	int				len;

	char_count = 0;
	p = (unsigned long)va_arg(ap, void *);
	len = ft_nbr_len_p(p);
	if (flag->width > len + 2)
		char_count = ft_p_width(p, flag, char_count, len);
	else
	{
		ft_putchar('0');
		ft_putchar('x');
		ft_putnbr_p(p);
		char_count = len + 2;
	}
	return (char_count);
}
