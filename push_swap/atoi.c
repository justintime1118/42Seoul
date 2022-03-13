/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:54:48 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/04 17:00:59 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	while (*s3 && *s4)
	{
		if (*s3 != *s4)
			return ((int)(*s3 - *s4));
		s3++;
		s4++;
	}
	return ((int)(*s3 - *s4));
}

int	ft_sign(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	else
		return (0);
}

int	ft_check_ovf(int nbr, int tmp)
{
	if (nbr < tmp)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;
	int	tmp;

	nbr = 0;
	tmp = 0;
	sign = ft_sign(*str);
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	if (sign)
		str++;
	else
		sign = 1;
	while (*str)
	{
		nbr *= 10;
		nbr += *str - '0';
		if (ft_check_ovf(nbr, tmp))
			return (0);
		tmp = nbr;
		str++;
	}
	nbr *= sign;
	return (nbr);
}
