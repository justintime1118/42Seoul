/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:51:54 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/19 05:06:50 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_simulation_init(t_var *vars)
{
	if (ft_mutex_init(vars) == -1)
		return ;
	if (ft_th_init(vars) == -1)
		return ;
}

long	ft_mutex_init(t_var *vars)
{
	long	i;

	i = 0;
	while (i <= vars->nb_of_philos)
	{
		if (pthread_mutex_init(&(vars->mutex_id[i][0]), 0) != 0)
		{
			ft_error("mutex init failed", vars, 0);
			return (-1);
		}
		if (pthread_mutex_init(&(vars->mutex_id[i][1]), 0) != 0)
		{
			ft_error("mutex init failed", vars, 0);
			return (-1);
		}
		i++;
	}
	if (pthread_mutex_init(&(vars->exit_mutex_id), 0) != 0)
	{
		ft_error("mutex init failed", vars, 0);
		return (-1);
	}
	return (0);
}

long	ft_th_init(t_var *vars)
{
	long	i;

	i = 1;
	while (i <= vars->nb_of_philos)
	{
		if (pthread_create(&(vars->th_id[i++]), 0, ft_routine, vars) != 0)
		{
			ft_error("thread create failed", vars, 0);
			return (-1);
		}
	}
	if (vars->nb_of_times_each_philo_must_eat != -2)
	{
		if (pthread_create(&(vars->f_monitor_id), 0, ft_f_monitor, vars) != 0)
		{
			ft_error("thread create failed", vars, 0);
			return (-1);
		}
	}
	if (pthread_create(&(vars->s_monitor_id), 0, ft_s_monitor, vars) != 0)
	{
		ft_error("thread create failed", vars, 0);
		return (-1);
	}
	return (0);
}

void	ft_simul_on(t_var *vars)
{
	struct timeval		tmv;

	if (gettimeofday(&tmv, NULL) == -1)
	{
		ft_error("gettimeofday failed", vars, 1);
		return ;
	}
	vars->begin_time = tmv.tv_sec * 1000 + tmv.tv_usec / 1000;
	vars->simul_switch = 1;
}
