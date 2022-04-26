/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:44:20 by jiyoo             #+#    #+#             */
/*   Updated: 2021/04/10 19:48:51 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int i;

	argc = 0;
	i = 0;
	while (argv[argc][i])
		write(1, &argv[argc][i++], 1);
	write(1, "\n", 1);
	return (0);
}
