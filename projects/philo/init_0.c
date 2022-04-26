/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:38:47 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/05 15:07:18 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(char **argv, t_var *vars)
{
	if (ft_arginit(argv, vars) == -1)
		return ;
	if (vars->nb_of_times_each_philo_must_eat == 0)
		return ;
	if (ft_meminit(vars) == -1)
		return ;
	ft_zeroinit(vars);
	ft_simulation_init(vars);
}

long	ft_arginit(char **argv, t_var *vars)
{
	vars->nb_of_philos = ft_atol(argv[1]);
	vars->time_to_die = ft_atol(argv[2]);
	vars->time_to_eat = ft_atol(argv[3]);
	vars->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		vars->nb_of_times_each_philo_must_eat = ft_atol(argv[5]);
	else
		vars->nb_of_times_each_philo_must_eat = -2;
	if (vars->nb_of_philos == -1 || vars->time_to_die == -1
		|| vars->time_to_eat == -1 || vars->time_to_sleep == -1
		|| vars->nb_of_times_each_philo_must_eat == -1)
	{
		ft_error("atol error", vars, 0);
		return (-1);
	}
	if (vars->nb_of_philos == 0 || vars->nb_of_times_each_philo_must_eat == 0)
	{
		ft_error("error: first and fifth arguments must be bigger than 0",
			vars, 0);
		return (-1);
	}
	return (0);
}

long	ft_meminit(t_var *vars)
{
	long	i;

	vars->mutex_id = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *)
			* (vars->nb_of_philos + 1));
	if (vars->mutex_id == 0)
	{
		ft_error("malloc failed", vars, 0);
		return (-1);
	}
	i = 0;
	while (i <= vars->nb_of_philos)
		vars->mutex_id[i++] = (pthread_mutex_t *)malloc
			(sizeof(pthread_mutex_t) * 2);
	vars->th_id = (pthread_t *)malloc(sizeof(pthread_t)
			* (vars->nb_of_philos + 1));
	vars->fork = (long *)malloc(sizeof(long) * (vars->nb_of_philos + 1));
	vars->nb_of_eating = (long *)malloc(sizeof(long)
			* (vars->nb_of_philos + 1));
	vars->last_eating_time = (long *)malloc(sizeof(long)
			* (vars->nb_of_philos + 1));
	if (ft_memerror_check(vars) == -1)
		return (-1);
	return (0);
}

long	ft_memerror_check(t_var *vars)
{
	long	i;

	i = 0;
	while (i <= vars->nb_of_philos)
	{
		if (vars->mutex_id[i++] == 0)
			return (-1);
	}
	if (vars->th_id == 0 || vars->fork == 0
		|| vars->nb_of_eating == 0
		|| vars->last_eating_time == 0)
		return (-1);
	return (0);
}

void	ft_zeroinit(t_var *vars)
{
	long	i;

	i = 0;
	vars->main_spin = 0;
	vars->simul_switch = 0;
	while (i <= vars->nb_of_philos)
	{
		vars->fork[i] = 0;
		vars->nb_of_eating[i] = 0;
		vars->last_eating_time[i] = 0;
		i++;
	}
}
