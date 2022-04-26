/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 01:42:20 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/19 20:39:33 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eatstamp(long philo_num, t_var *vars)
{
	long	current_time;

	if (pthread_mutex_lock(&vars->mutex_id[0][STMP]) != 0)
		ft_error("mutex lock failed", vars, 1);
	current_time = ft_gettime(vars);
	if (current_time - vars->last_eating_time[philo_num] <= vars->time_to_die)
	{
		vars->last_eating_time[philo_num] = current_time;
		printf("%ld %ld is eating\n", current_time, philo_num);
		vars->nb_of_eating[philo_num]++;
	}
	if (pthread_mutex_unlock(&vars->mutex_id[0][STMP]) != 0)
		ft_error("mutex unlock failed", vars, 1);
}

void	ft_forkstamp(long philo_num, t_var *vars)
{
	long	current_time;

	if (pthread_mutex_lock(&vars->mutex_id[0][STMP]) != 0)
		ft_error("mutex lock failed", vars, 1);
	current_time = ft_gettime(vars);
	if (current_time - vars->last_eating_time[philo_num] <= vars->time_to_die)
	{
		if (vars->simul_switch == 1)
			printf("%ld %ld has taken a fork\n", current_time, philo_num);
	}
	if (pthread_mutex_unlock(&vars->mutex_id[0][STMP]) != 0)
		ft_error("mutex unlock failed", vars, 1);
}

void	ft_sleepstamp(long philo_num, t_var *vars)
{
	if (pthread_mutex_lock(&vars->mutex_id[0][STMP]) != 0)
		ft_error("mutex lock failed", vars, 1);
	printf("%ld %ld is sleeping\n", ft_gettime(vars), philo_num);
	if (pthread_mutex_unlock(&vars->mutex_id[0][STMP]) != 0)
		ft_error("mutex unlock failed", vars, 1);
}

void	ft_deathstamp(long philo_num, t_var *vars)
{
	if (pthread_mutex_lock(&vars->mutex_id[0][STMP]) != 0)
		ft_error("mutex lock failed", vars, 1);
	printf("%ld %ld died\n", ft_gettime(vars), philo_num);
	if (pthread_mutex_unlock(&vars->exit_mutex_id) != 0)
		write(1, "mutex unlock failed: fatal\n", 26);
}

void	ft_fullstamp(t_var *vars)
{
	if (pthread_mutex_lock(&vars->mutex_id[0][STMP]) != 0)
		ft_error("mutex lock failed", vars, 1);
	write(1, "every philosopher have had enough\n", 35);
	if (pthread_mutex_unlock(&vars->exit_mutex_id) != 0)
		write(1, "mutex unlock failed: fatal\n", 26);
}
