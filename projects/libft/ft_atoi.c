/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:54:48 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/19 23:30:09 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sign(const char *str, int sign)
{
	while ((9 <= *str && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign = -1;
	}
	return (sign);
}

const char	*ft_index(const char *str)
{
	while ((9 <= *str && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
	}
	return (str);
}

int	ft_check_ovf(long long nbr, long long tmp, int sign)
{
	if (nbr < tmp)
	{
		if (sign == 1)
			return (1);
		else
			return (-1);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long long	nbr;
	int			sign;
	long long	tmp;

	nbr = 0;
	tmp = 0;
	sign = 1;
	sign = ft_sign(str, sign);
	str = ft_index(str);
	while (*str && '0' <= *str && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - '0';
		str++;
		if (ft_check_ovf(nbr, tmp, sign) == 1)
			return (-1);
		if (ft_check_ovf(nbr, tmp, sign) == -1)
			return (0);
		tmp = nbr;
	}
	nbr *= sign;
	return ((int)nbr);
}
