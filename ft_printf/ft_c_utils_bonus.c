/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:51:17 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/13 18:35:02 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_c_dash(int char_count, char c, t_list *flag)
{
	int	width_adder;

	width_adder = (flag->width) - 1;
	ft_putchar(c);
	while (width_adder-- > 0)
	{
		char_count++;
		ft_putchar(' ');
	}
	return (char_count);
}

int	ft_c_width(int char_count, char c, t_list *flag)
{
	int	width_adder;

	width_adder = (flag->width) - 1;
	while (width_adder-- > 0)
	{
		char_count++;
		ft_putchar(' ');
	}
	ft_putchar(c);
	return (char_count);
}
