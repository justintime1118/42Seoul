/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:36:42 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/16 15:25:35 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dash_parse(const char *input, int idx, t_list *flag)
{
	if (input[idx] == '-')
	{
		flag->dash = 1;
		while (input[idx] == '-')
			idx++;
	}
	return (idx);
}

int	ft_zero_parse(const char *input, int idx, t_list *flag)
{
	if (input[idx] == '0')
	{
		flag->zero = 1;
		idx++;
	}
	return (idx);
}

int	ft_width_parse(const char *input, int idx, t_list *flag)
{
	if ('0' <= input[idx] && input[idx] <= '9')
	{
		flag->width = ft_atoi(input + idx);
		while ('0' <= input[idx] && input[idx] <= '9')
			idx++;
	}
	return (idx);
}

int	ft_precision_parse(const char *input, int idx, t_list *flag)
{
	if (input[idx] == '.')
	{
		idx++;
		if ('0' <= input[idx] && input[idx] <= '9')
		{
			flag->precision = ft_atoi(input + idx);
			while ('0' <= input[idx] && input[idx] <= '9')
				idx++;
		}
		else
			flag->precision = 0;
	}
	return (idx);
}

void	ft_form_id_parse(const char *input, int idx, t_list *flag)
{
	if (ft_is_form_id(input[idx]))
		flag->type = (int)input[idx];
}
