/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:14:15 by jiyoo             #+#    #+#             */
/*   Updated: 2021/04/11 17:16:15 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*g_base;
int		g_len;

int		ft_atoi(char *str)
{
	int nbr;
	int sign;

	nbr = 0;
	sign = 1;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		++str;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while ('0' <= *str && *str <= '9')
	{
		nbr *= 10;
		nbr += (sign * (*(str++) - '0'));
	}
	return (nbr);
}

int		ft_get_len(void)
{
	int chk[256];
	int i;

	i = 0;
	while (i < 256)
		chk[i++] = 0;
	g_len = 0;
	while (g_base[g_len])
	{
		if (chk[(int)g_base[g_len]] ||
				g_base[g_len] == '+' ||
				g_base[g_len] == '-' ||
				('\t' <= g_base[g_len] && g_base[g_len] <= '\r') ||
				g_base[g_len] == ' ')
			return (0);
		chk[(int)g_base[g_len++]] = 1;
	}
	return (1);
}

int		ft_change_nbr_base(int nbr, char *base)
{
	long long tmp;

	g_base = base;
	if (ft_get_len() == 0 || g_len == 0 || g_len == 1)
		return ;
	tmp = nbr;
	while((nbr/g_len) <= g_len)
	{
		
			
}

int		ft_atoi_base(char *str, char *base)
{
	
}
