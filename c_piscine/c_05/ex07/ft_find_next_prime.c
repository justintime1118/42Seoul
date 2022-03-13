/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 01:21:53 by jiyoo             #+#    #+#             */
/*   Updated: 2021/04/10 19:37:08 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	long long i;
	long long long_nb;

	i = 2;
	long_nb = nb;
	if (long_nb <= 1)
		return (0);
	if (long_nb <= 3)
		return (1);
	while (i * i <= long_nb)
	{
		if (long_nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	long long i;

	if (nb == 0 || nb == 1)
		return (2);
	i = nb;
	while (!(ft_is_prime(i)))
		i += 1;
	return (i);
}
