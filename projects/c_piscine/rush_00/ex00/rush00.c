/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:34:08 by snam              #+#    #+#             */
/*   Updated: 2021/03/28 16:28:28 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_last_line_print(int count_x, int x)
{
	while (0 < count_x && count_x <= x)
	{
		if (count_x == 1 || count_x == x)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
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
			ft_putchar('|');
		}
		else
		{
			ft_putchar(' ');
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
		if (count_y == 1 || count_y == y)
			first_last_line_print(count_x, x);
		else
			middle_line_print(count_x, x);
		ft_putchar('\n');
		count_y++;
	}
}
