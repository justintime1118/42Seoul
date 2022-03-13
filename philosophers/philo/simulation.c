/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:25:10 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/11 19:53:03 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(int philo_num, int former_philo_num, t_var *vars)
{
	if (pthread_mutex_lock(&vars->mutex_id[philo_num]) != 0)
		ft_error("mutex lock failed");
	vars->fork[philo_num] = 1;
	ft_timestamp(philo_num, 'f', vars);
	if (pthread_mutex_lock(&vars->mutex_id[former_philo_num]) != 0)
		ft_error("mutex lock failed");
	vars->fork[former_philo_num] = 1;
	ft_timestamp(philo_num, 'f', vars);
	ft_sleep(philo_num, vars, 'e');
	vars->nb_of_eating[philo_num]++;
	vars->fork[philo_num] = 0;
	vars->fork[former_philo_num] = 0;
	if (pthread_mutex_unlock(&vars->mutex_id[philo_num]) != 0
		|| pthread_mutex_unlock(&vars->mutex_id[former_philo_num]) != 0)
		ft_error("mutex unlock failed");
}

void	ft_sleep(int philo_num, t_var *vars, char flag)
{
	long	start_time;

	ft_timestamp(philo_num, flag, vars);
	start_time = ft_gettime(vars);
	if (flag == 'e')
	{
		while (ft_gettime(vars) - start_time < vars->time_to_eat)
			usleep(10);
	}
	if (flag == 's')
	{
		while (ft_gettime(vars) - start_time < vars->time_to_sleep)
			usleep(10);
	}
}

void	*ft_routine(void *arg)
{
	unsigned int		philo_num;
	unsigned int		former_philo_num;
	static unsigned int	cnt;
	t_var				*vars;

	vars = (t_var *)arg;
	if (pthread_mutex_lock(&vars->mutex_id[0]) != 0)
		ft_error("mutex lock failed");
	philo_num = ++cnt;
	if (pthread_mutex_unlock(&vars->mutex_id[0]) != 0)
		ft_error("mutex unlock failed");
	if (philo_num == 1)
		former_philo_num = vars->nb_of_philos;
	else
		former_philo_num = philo_num - 1;
	if (philo_num % 2 == 1)
		usleep(1000 * (vars->time_to_eat));
	while (1)
	{
		ft_eat(philo_num, former_philo_num, vars);
		ft_sleep(philo_num, vars, 's');
		ft_timestamp(philo_num, 't', vars);
	}
	return (vars);
}

void	*ft_monitor(void *arg)
{
	unsigned int	philo_num;
	t_var			*vars;
	long			time_passed;

	vars = (t_var *)arg;
	while (1)
	{
		philo_num = 1;
		while (philo_num <= vars->nb_of_philos)
		{
			if (pthread_mutex_lock(&vars->mutex_id[0]) != 0)
				ft_error("mutex lock failed");
			time_passed = ft_gettime(vars)
				 - (vars->last_eating_time[philo_num]);
			if (time_passed > vars->time_to_die)
			{
				printf("%ld %u died\n", time_passed, philo_num);
				exit(0);
			}
			if (pthread_mutex_unlock(&vars->mutex_id[0]) != 0)
				ft_error("mutex unlock failed");
			philo_num++;
		}
	}
	return (vars);
}
