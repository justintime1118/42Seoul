/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:25:10 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/10 18:58:35 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(int philo_num, int former_philo_num, t_var *vars)
{
	long	start_time;

	if (vars->fork[former_philo_num] == 1)
		usleep(1000 * vars->time_to_eat);
	if (pthread_mutex_lock(&vars->mutex_id[philo_num]) != 0)
		ft_error("mutex lock failed");
	vars->fork[philo_num] = 1;
	ft_timestamp(philo_num, 'f', vars);
	if (pthread_mutex_lock(&vars->mutex_id[former_philo_num]) != 0)
		ft_error("mutex lock failed");
	vars->fork[former_philo_num] = 1;
	ft_timestamp(philo_num, 'f', vars);
	ft_timestamp(philo_num, 'e', vars);
	start_time = vars->last_eating_time[philo_num];
	while (ft_gettime(vars) - start_time < vars->time_to_eat)
		usleep(10);
	vars->nb_of_eating[philo_num]++;
	vars->fork[philo_num] = 0;
	vars->fork[former_philo_num] = 0;
	if (pthread_mutex_unlock(&vars->mutex_id[philo_num]) != 0
		|| pthread_mutex_unlock(&vars->mutex_id[former_philo_num]) != 0)
		ft_error("mutex unlock failed");
}

void	ft_sleep(int philo_num, t_var *vars)
{
	long	start_time;

	ft_timestamp(philo_num, 's', vars);
	start_time = ft_gettime(vars);
	while (ft_gettime(vars) - start_time < vars->time_to_eat)
		usleep(10);
}

void	*ft_routine(void *vars)
{
	unsigned int		philo_num;
	unsigned int		former_philo_num;
	static unsigned int	cnt;
	struct timeval		tmv;

	philo_num = ++cnt;
	if (philo_num == 1)
		former_philo_num = ((t_var *)vars)->nb_of_philos;
	else
		former_philo_num = philo_num - 1;
	if (gettimeofday(&tmv, NULL) == -1)
		ft_error("timestamp error");
	if (((t_var *)vars)->begin_time == 0)
		((t_var *)vars)->begin_time = tmv.tv_sec * 1000 + tmv.tv_usec / 1000;
	((t_var *)vars)->last_eating_time[philo_num] = ((t_var *)vars)->begin_time;
	if (philo_num % 2 == 1)
		usleep(1000 * (((t_var *)vars)->time_to_die) / 2);
	while (1)
	{
		ft_eat(philo_num, former_philo_num, (t_var *)vars);
		ft_sleep(philo_num, (t_var *)vars);
		ft_timestamp(philo_num, 't', (t_var *)vars);
	}
	return (vars);
}

void	*ft_monitor(void *vars)
{
	unsigned int	philo_num;
	long			time_passed;

	while (1)
	{
		philo_num = 1;
		while (philo_num <= ((t_var *)vars)->nb_of_philos)
		{
			if (pthread_mutex_lock(&((t_var *)vars)->mutex_id[0]) != 0)
				ft_error("mutex lock failed");
			time_passed = (ft_gettime(vars)
					- ((t_var *)vars)->last_eating_time[philo_num]);
			if (time_passed > ((t_var *)vars)->time_to_die)
			{
				ft_timestamp(philo_num, 'd', vars);
				exit(0);
			}
			if (pthread_mutex_unlock(&((t_var *)vars)->mutex_id[0]) != 0)
				ft_error("mutex unlock failed");
			philo_num++;
			usleep(100);
		}
	}
	return (vars);
}

void	*ft_simulation(void *vars)
{
	unsigned int	i;

	i = 0;
	while (i <= ((t_var *)vars)->nb_of_philos)
	{
		if (pthread_mutex_init(&(((t_var *)vars)->mutex_id[i]), 0) != 0)
			ft_error("mutex initiation error");
		i++;
	}
	i = 1;
	while (i <= ((t_var *)vars)->nb_of_philos)
	{
		if (pthread_create(&(((t_var *)vars)->th_id[i]),
				0, ft_routine, vars) != 0)
			ft_error("philosopher creation error");
		i++;
	}
	if (pthread_create(&(((t_var *)vars)->monitor_id),
			0, ft_monitor, vars) != 0)
		ft_error("monitor creation error");
	return (vars);
}
