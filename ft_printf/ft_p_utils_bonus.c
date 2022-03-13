/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:25:37 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/16 17:28:46 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_p_width(unsigned long p, t_list *flag, int char_count, int len)
{
	int	width_adder;

	width_adder = flag->width;
	if (flag->dash == 1)
	{
		ft_putchar('0');
		ft_putchar('x');
		ft_putnbr_p(p);
	}
	while (width_adder-- > (len + 2))
	{
		ft_putchar(' ');
		char_count++;
	}
	if (flag->dash == 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		ft_putnbr_p(p);
	}
	return (flag->width);
}
