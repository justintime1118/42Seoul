/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:52:08 by jiyoo             #+#    #+#             */
/*   Updated: 2021/04/10 13:31:02 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fib(int n, int a, int b)
{
	if (n == 0)
		return (a);
	if (n == 1)
		return (b);
	return (ft_fib(n - 1, b, a + b));
}

int		ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	return (ft_fib(index, 0, 1));
}
