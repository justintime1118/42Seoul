/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_id_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:10:52 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/14 10:46:55 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_form_id(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_c_processor(t_list *flag, va_list ap)
{
	int		char_count;
	char	c;

	char_count = 0;
	c = va_arg(ap, int);
	if (flag->dash == 1)
		char_count = ft_c_dash(char_count, c, flag);
	else if (flag->width)
		char_count = ft_c_width(char_count, c, flag);
	else
		ft_putchar(c);
	return (char_count + 1);
}

int	ft_s_processor(t_list *flag, va_list ap)
{
	int		char_count;
	char	*s;
	int		len;

	char_count = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (flag->precision < len && flag->precision >= 0)
		char_count = ft_s_precision(char_count, s, flag);
	else if (flag->width > len)
		char_count = ft_s_width(char_count, s, flag, len);
	else
	{
		ft_putstr(s);
		char_count += len;
	}
	return (char_count);
}

int	ft_i_processor(t_list *flag, va_list ap)
{
	int		char_count;
	int		d;
	int		len;

	char_count = 0;
	d = va_arg(ap, int);
	len = ft_nbr_len(d);
	if (d == 0)
		char_count = ft_i_zero(char_count, flag);
	else if (d > 0)
		char_count = ft_i_posi(char_count, d, len, flag);
	else
		char_count = ft_i_nega(char_count, d, len, flag);
	return (char_count);
}

int	ft_u_processor(t_list *flag, va_list ap)
{
	int				char_count;
	unsigned int	u;
	int				len;

	char_count = 0;
	u = va_arg(ap, unsigned int);
	len = ft_nbr_len(u);
	if (u == 0)
		char_count = ft_i_zero(char_count, flag);
	else if (flag->precision > 0)
		char_count = ft_u_precision(char_count, u, len, flag);
	else if (flag->width > len)
		char_count = ft_u_width(u, len, flag);
	else
	{
		ft_putnbr_u(u);
		char_count += len;
	}
	return (char_count);
}
