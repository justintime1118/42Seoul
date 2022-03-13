/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:44:41 by jiyoo             #+#    #+#             */
/*   Updated: 2021/05/11 16:08:56 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (97 <= c && c <= 122)
		return (1);
	if (65 <= c && c <= 90)
		return (1);
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}
