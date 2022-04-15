/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:35:47 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/19 18:54:47 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_var	*vars;

	if ((argc != 5 && argc != 6))
	{
		write(1, "wrong input format\n", 20);
		return (1);
	}
	vars = (t_var *)malloc(sizeof(t_var));
	if (vars == 0)
	{
		write(1, "malloc failed\n", 15);
		return (1);
	}
	vars->error_flag = 0;
	ft_init(argv, vars);
	if (vars->error_flag == 1)
		return (1);
	while (vars->main_spin == 0)
		ft_spin(vars);
	if (vars->error_flag == 1)
		return (1);
	ft_simul_on(vars);
	if (pthread_mutex_lock(&vars->exit_mutex_id) != 0)
		write(1, "mutex lock failed: fatal\n", 26);
	return (0);
}
