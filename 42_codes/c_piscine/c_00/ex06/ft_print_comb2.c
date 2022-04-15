/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:30:03 by jiyoo             #+#    #+#             */
/*   Updated: 2021/03/31 17:59:52 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_comb(int a, int b, int end)
{
	ft_putchar(48 + (a / 10));
	ft_putchar(48 + (a % 10));
	ft_putchar(' ');
	ft_putchar(48 + (b / 10));
	ft_putchar(48 + (b % 10));
	if (end)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;
	int end;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			end = !(a == 98 && b == 99);
			ft_write_comb(a, b, end);
			b++;
		}
		a++;
	}
}
