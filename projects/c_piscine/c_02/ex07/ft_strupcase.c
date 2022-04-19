/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:18:12 by jiyoo             #+#    #+#             */
/*   Updated: 2021/04/04 12:19:54 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_lowercase(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_lowercase(str[i]))
			str[i] = str[i] - 32;
		++i;
	}
	return (str);
}
