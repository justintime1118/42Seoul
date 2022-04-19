/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:15:12 by jiyoo             #+#    #+#             */
/*   Updated: 2021/04/04 12:15:14 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_printable(char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

int		ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (!is_printable(str[i++]))
			return (0);
	return (1);
}
