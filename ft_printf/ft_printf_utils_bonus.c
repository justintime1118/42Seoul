/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 11:59:48 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/16 16:54:33 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_nbr_len(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_atoi(const char *str)
{
	long long	nbr;

	nbr = 0;
	while ('0' <= *str && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - '0';
		str++;
	}
	return ((int)nbr);
}

int	ft_strlen(const char *s1)
{
	int	len;

	if (s1 == NULL)
		return (0);
	len = 0;
	while (s1[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	long long	len;
	char		*ptr;

	len = ft_strlen(s1);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (0);
	ptr[len] = 0;
	while (--len >= 0)
		ptr[len] = s1[len];
	return (ptr);
}

t_list	*ft_lstnew(void)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (new_elem == 0)
		return (NULL);
	new_elem->type = 0;
	new_elem->dash = 0;
	new_elem->zero = 0;
	new_elem->width = 0;
	new_elem->precision = -1;
	return (new_elem);
}
