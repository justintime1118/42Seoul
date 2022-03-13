/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:45:35 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/13 18:44:27 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_s_precision(int char_count, char *s, t_list *flag)
{
	int		space;
	char	*s_precision;

	s_precision = ft_strdup(s);
	s_precision[flag->precision] = '\0';
	if (flag->width > flag->precision)
	{
		space = flag->width - flag->precision;
		if (flag->dash == 1)
			ft_putstr(s_precision);
		while (space--)
		{
			ft_putchar(' ');
			char_count++;
		}
		if (flag->dash == 0)
			ft_putstr(s_precision);
	}
	else
		ft_putstr(s_precision);
	free(s_precision);
	return (char_count + flag->precision);
}

int	ft_s_width(int char_count, char *s, t_list *flag, int len)
{
	int	space;

	space = flag->width - len;
	if (flag->dash == 1)
		ft_putstr(s);
	while (space--)
	{
		ft_putchar(' ');
		char_count++;
	}
	if (flag->dash == 0)
		ft_putstr(s);
	return (char_count + len);
}
