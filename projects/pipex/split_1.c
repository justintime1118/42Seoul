/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:02:44 by jiyoo             #+#    #+#             */
/*   Updated: 2021/11/20 13:34:36 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_strput(char *dst, char *from, char *until)
{
	while (from < until)
		*(dst++) = *(from++);
	*dst = 0;
}

void	ft_split_check(char *str)
{
	int	i;

	i = 0;
	if (str == 0 || *str == 0)
		exit(1);
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			break ;
	}
	if (str[i] == 0)
		exit(1);
}
