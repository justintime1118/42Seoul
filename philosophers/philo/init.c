/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:38:47 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/11 21:16:38 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_var	*ft_init(char **argv)
{
	t_var	*vars;

	vars = (t_var *)malloc(sizeof(t_var));
	vars->nb_of_philos = ft_atoi(argv[1]);
	vars->time_to_die = ft_atoi(argv[2]);
	vars->time_to_eat = ft_atoi(argv[3]);
	vars->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		vars->nb_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	vars->mutex_id = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (vars->nb_of_philos + 1));
	vars->th_id = (pthread_t *)malloc(sizeof(pthread_t)
			* (vars->nb_of_philos + 1));
	vars->fork = (int *)malloc(sizeof(int) * (vars->nb_of_philos + 1));
	vars->nb_of_eating = (unsigned int *)malloc(sizeof(unsigned int)
			* (vars->nb_of_philos + 1));
	vars->last_eating_time = (long *)malloc(sizeof(long)
			* (vars->nb_of_philos + 1));
	if (vars->th_id == 0 || vars->mutex_id == 0
		|| vars->fork == 0 || vars->nb_of_eating == 0
		|| vars->last_eating_time == 0)
		ft_error("vars malloc failed");
	ft_zeroinit(vars);
	ft_simulation_init(vars);
	return (vars);
}

void	ft_simulation_init(t_var *vars)
{
	unsigned int		i;
	struct timeval		tmv;

	i = 0;
	while (i <= vars->nb_of_philos)
	{
		if (pthread_mutex_init(&(vars->mutex_id[i]), 0) != 0)
			ft_error("mutex initiation failed");
		i++;
	}
	if (gettimeofday(&tmv, NULL) == -1)
		ft_error("timestamp error");
	vars->begin_time = tmv.tv_sec * 1000 + tmv.tv_usec / 1000;
	i = 1;
	while (i <= vars->nb_of_philos)
	{
		if (pthread_create(&(vars->th_id[i]), 0, ft_routine, vars) != 0)
			ft_error("philosopher creation failed");
		i++;
	}
	if (pthread_create(&(vars->monitor_id), 0, ft_monitor, vars) != 0)
		ft_error("monitor creation failed");
}

void	ft_zeroinit(t_var *vars)
{
	unsigned int	i;

	i = 0;
	while (i <= vars->nb_of_philos)
	{
		vars->fork[i] = 0;
		vars->nb_of_eating[i] = 0;
		vars->last_eating_time[i] = 0;
		i++;
	}
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	nbr;
	unsigned int	tmp;

	nbr = 0;
	tmp = 0;
	if (str == 0 || *str == 0 || *str < '0' || '9' < *str)
		ft_error("atoi wrong parameter");
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			ft_error("atoi wrong parameter");
		nbr *= 10;
		nbr += *str - '0';
		str++;
		if (nbr < tmp)
			ft_error("atoi overflow: too big argument");
		tmp = nbr;
	}
	return (nbr);
}
