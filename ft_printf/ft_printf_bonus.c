/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:00:18 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/17 14:23:50 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_list	*ft_flag_init(t_list *flag)
{
	flag->type = 0;
	flag->dash = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->precision = -1;
	return (flag);
}

int	ft_flag_parse(const char *input, int idx, t_list *flag)
{
	idx++;
	idx = ft_dash_parse(input, idx, flag);
	idx = ft_zero_parse(input, idx, flag);
	idx = ft_width_parse(input, idx, flag);
	idx = ft_precision_parse(input, idx, flag);
	ft_form_id_parse(input, idx, flag);
	return (idx);
}

int	ft_form_id_processor(const char *input, int idx, t_list *flag, va_list ap)
{
	int		char_count;

	char_count = 0;
	if (flag->type == '%')
	{
		write(1, input + idx, 1);
		char_count++;
	}
	if (flag->type == (int) 'c')
		char_count = ft_c_processor(flag, ap);
	if (flag->type == (int) 's')
		char_count = ft_s_processor(flag, ap);
	if (flag->type == (int) 'd' || flag->type == (int) 'i')
		char_count = ft_i_processor(flag, ap);
	if (flag->type == (int) 'u')
		char_count = ft_u_processor(flag, ap);
	if (flag->type == (int) 'x')
		char_count = ft_x_lower_processor(flag, ap);
	if (flag->type == (int) 'X')
		char_count = ft_x_upper_processor(flag, ap);
	if (flag->type == ((unsigned long int) 'p'))
		char_count = ft_p_processor(flag, ap);
	return (char_count);
}

int	ft_input_processor(const char *input,
	va_list ap, t_list *flag, int char_count)
{
	int		idx;

	idx = 0;
	flag = ft_lstnew();
	while (1)
	{
		if (input[idx] == '\0')
			break ;
		else if (input[idx] == '%')
		{
			idx = ft_flag_parse(input, idx, flag);
			if (ft_is_form_id(input[idx]))
				char_count += ft_form_id_processor(input, idx, flag, ap);
			flag = ft_flag_init(flag);
		}
		else if (input[idx] != '%')
		{
			char_count++;
			ft_putchar(input[idx]);
		}
		idx++;
	}
	free(flag);
	return (char_count);
}

int	ft_printf(const char *input, ...)
{
	va_list		ap;
	int			char_count;
	t_list		*flag;

	flag = NULL;
	if (input == 0 || *input == '\0')
		return (-1);
	va_start(ap, input);
	char_count = 0;
	char_count = ft_input_processor(input, ap, flag, char_count);
	va_end(ap);
	return (char_count);
}
#include <stdio.h>
#include <limits.h>

int main()
{
	/*
	printf("%.d", 12345);
	printf("%.0d", 12345);
	printf("%.3d", 12345);
	printf("%.7d", 12345);
	printf("%-.7d", 12345);
	printf("%-9.7d", 12345);
	printf("%9.7d", 12345);
	printf("%-7.9d", 12345);
	printf("%-3.7d", 12345);
	printf("%-7.3d", 12345);
	printf("%-7.9d", -12345);
	printf("%.3s\n\n\n", "abcde");

	ft_printf("%.d", 12345);
	ft_printf("%.0d", 12345);
	ft_printf("%.3d", 12345);
	ft_printf("%.7d", 12345);
	ft_printf("%-.7d", 12345);
	ft_printf("%-9.7d", 12345);
	ft_printf("%9.7d", 12345);
	ft_printf("%-7.9d", 12345);
	ft_printf("%-3.7d", 12345);
	ft_printf("%-7.3d", 12345);
	ft_printf("%-7.9d", -12345);
	ft_printf("%.3s", "abcde");
	*/
	int a;
	int b;

	a = printf("%012i\n", -71823);
	b = ft_printf("%012i\n", -71823);
	printf("diff is %d", a-b);
}