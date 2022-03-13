/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:00:04 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/24 12:29:10 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	long long	len;
	char		*ret;

	len = 0;
	while (src[len]) //길이 구하기
		++len;
	ret = (char*)malloc(len + 1); // 문자열 맨끝에 종단문자를 넣기 위해서 len + 1만큼 메모리를 할당.
	ret[len] = 0; //종단문자 넣기
	while (--len >= 0)
		ret[len] = src[len];
	return (ret);
}
