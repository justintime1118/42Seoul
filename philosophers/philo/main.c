/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:35:47 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/11 16:58:52 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_var	*vars;

	if ((argc != 5 && argc != 6))
		ft_error("invalid argument number");
	vars = ft_init(argv);
	while (1)
	{
		ft_full_detector(vars);
		usleep(1000);
	}
	return (0);
}
