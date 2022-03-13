/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:25:48 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/14 10:56:09 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_i_zero(int char_count, t_list *flag)
{
	if (flag->precision >= 0)
		char_count = ft_i_zero_precision(char_count, flag);
	else if (flag->width > 0)
		char_count = ft_i_zero_width(flag);
	else
	{
		ft_putchar('0');
		char_count = 1;
	}
	return (char_count);
}

int	ft_i_posi(int char_count, int d, int len, t_list *flag)
{
	if (flag->precision >= 0)
		char_count = ft_i_posi_precision(char_count, d, len, flag);
	else if (flag->width > len)
		char_count = ft_i_posi_width(d, len, flag);
	else
	{
		ft_putnbr_i(d);
		char_count += len;
	}
	return (char_count);
}

int	ft_i_nega(int char_count, int d, int len, t_list *flag)
{
	if (flag->precision >= 0)
		char_count = ft_i_nega_precision(char_count, d, len, flag);
	else if (flag->width > len)
		char_count = ft_i_nega_width(d, len, flag);
	else
	{
		ft_putchar('-');
		ft_putnbr_i(d);
		char_count += (len + 1);
	}
	return (char_count);
}
