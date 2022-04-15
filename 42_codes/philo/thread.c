/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:25:10 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/19 20:39:22 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	long		philo_num;
	long		former_philo_num;
	static long	cnt;
	t_var		*vars;

	vars = (t_var *)arg;
	if (pthread_mutex_lock(&vars->mutex_id[0][CNT]) != 0)
		ft_error("mutex lock failed", vars, 0);
	philo_num = ++cnt;
	if (pthread_mutex_unlock(&vars->mutex_id[0][CNT]) != 0)
		ft_error("mutex unlock failed", vars, 0);
	if (philo_num == 1)
		former_philo_num = vars->nb_of_philos;
	else
		former_philo_num = philo_num - 1;
	while (vars->simul_switch == 0)
		ft_spin(vars);
	if (philo_num % 2 == 1)
		ft_wait(vars->time_to_eat / 2 + 1, vars);
	while (vars->simul_switch == 1 && vars->error_flag == 0)
	{
		ft_eat(philo_num, former_philo_num, vars);
		ft_sleep_think(philo_num, vars);
	}
	return (NULL);
}

void	ft_eat(long philo_num, long former_philo_num, t_var *vars)
{
	if (pthread_mutex_lock(&vars->mutex_id[philo_num][FORK]) != 0)
		ft_error("mutex lock failed", vars, 1);
	vars->fork[philo_num] = 1;
	ft_forkstamp(philo_num, vars);
	if (pthread_mutex_lock(&vars->mutex_id[former_philo_num][FORK]) != 0)
		ft_error("mutex lock failed", vars, 1);
	vars->fork[former_philo_num] = 1;
	if (pthread_mutex_lock(&vars->mutex_id[philo_num][MNT]) != 0)
		ft_error("mutex lock failed", vars, 1);
	ft_forkstamp(philo_num, vars);
	ft_eatstamp(philo_num, vars);
	if (pthread_mutex_unlock(&vars->mutex_id[philo_num][MNT]) != 0)
		ft_error("mutex unlock failed", vars, 1);
	ft_wait(vars->time_to_eat, vars);
	vars->fork[philo_num] = 0;
	vars->fork[former_philo_num] = 0;
	if (pthread_mutex_unlock(&vars->mutex_id[philo_num][FORK]) != 0
		|| pthread_mutex_unlock(&vars->mutex_id[former_philo_num][FORK]) != 0)
		ft_error("mutex unlock failed", vars, 1);
}

void	ft_sleep_think(long philo_num, t_var *vars)
{
	ft_sleepstamp(philo_num, vars);
	ft_wait(vars->time_to_sleep, vars);
	if (pthread_mutex_lock(&vars->mutex_id[0][STMP]) != 0)
		ft_error("mutex lock failed", vars, 1);
	if (vars->simul_switch == 1)
		printf("%ld %ld is thinking\n", ft_gettime(vars), philo_num);
	if (pthread_mutex_unlock(&vars->mutex_id[0][STMP]) != 0)
		ft_error("mutex unlock failed", vars, 1);
}

void	*ft_s_monitor(void *arg)
{
	t_var	*vars;
	long	philo_num;

	vars = (t_var *)arg;
	if (pthread_mutex_lock(&vars->exit_mutex_id) != 0)
		ft_error("mutex lock failed: fatal", vars, 0);
	vars->main_spin = 1;
	while (vars->simul_switch == 0)
		ft_spin(vars);
	while (vars->simul_switch == 1 && vars->error_flag == 0)
	{
		philo_num = 1;
		while (philo_num <= vars->nb_of_philos)
		{
			if (pthread_mutex_lock(&vars->mutex_id[philo_num][MNT]) != 0)
				ft_error("mutex lock failed", vars, 1);
			if (ft_gettime(vars) - vars->last_eating_time[philo_num]
				> vars->time_to_die)
				ft_deathstamp(philo_num, vars);
			if (pthread_mutex_unlock(&vars->mutex_id[philo_num++][MNT]) != 0)
				ft_error("mutex unlock failed", vars, 1);
		}
	}
	ft_error("something went wrong while thread init", vars, 1);
	return (NULL);
}

void	*ft_f_monitor(void *arg)
{
	t_var	*vars;
	long	philo_num;

	vars = (t_var *)arg;
	while (vars->simul_switch == 0)
		ft_spin(vars);
	while (vars->simul_switch == 1 && vars->error_flag == 0)
	{
		philo_num = 1;
		while (philo_num <= vars->nb_of_philos)
		{
			if (vars->nb_of_eating[philo_num]
				< vars->nb_of_times_each_philo_must_eat)
				break ;
			philo_num++;
		}
		if (philo_num > vars->nb_of_philos)
			ft_fullstamp(vars);
	}
	return (NULL);
}
