/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:34:08 by snam              #+#    #+#             */
/*   Updated: 2021/03/28 15:49:33 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_line_print(int count_x, int x)
{
	while (0 < count_x && count_x <= x)
	{
		if (count_x == 1)
		{
			ft_putchar('A');
		}
		else if (1 < count_x && count_x < x)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar('C');
		}
		count_x++;
	}
}

void	middle_line_print(int count_x, int x)
{
	while (0 < count_x && count_x <= x)
	{
		if (count_x == 1 || count_x == x)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		count_x++;
	}
}

void	last_line_print(int count_x, int x)
{
	while (0 < count_x && count_x <= x)
	{
		if (count_x == 1)
		{
			ft_putchar('C');
		}
		else if (1 < count_x && count_x < x)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar('A');
		}
		count_x++;
	}
}

void	rush(int x, int y)
{
	int count_x;
	int count_y;

	count_y = 1;
	while (0 < count_y && count_y <= y)
	{
		count_x = 1;
		if (count_y == 1)
			first_line_print(count_x, x);
		else if (1 < count_y && count_y < y)
			middle_line_print(count_x, x);
		else
			last_line_print(count_x, x);
		ft_putchar('\n');
		count_y++;
	}
}
