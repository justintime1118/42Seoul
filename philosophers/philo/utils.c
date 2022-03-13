/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:18:10 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/10 18:54:28 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_timestamp(int philo_num, char flag, t_var *vars)
{
	long			current_time;

	current_time = ft_gettime(vars);
	if (flag == 'f')
		printf("%ld %d has taken a fork\n", current_time, philo_num);
	else if (flag == 'e')
	{
		if (pthread_mutex_lock(&vars->mutex_id[0]) != 0)
			ft_error("mutex lock failed");
		vars->last_eating_time[philo_num] = current_time;
		printf("%ld %d is eating\n", current_time, philo_num);
		if (pthread_mutex_unlock(&vars->mutex_id[0]) != 0)
			ft_error("mutex unlock failed");
	}
	else if (flag == 's')
		printf("%ld %d is sleeping\n", current_time, philo_num);
	else if (flag == 't')
		printf("%ld %d is thinking\n", current_time, philo_num);
	else if (flag == 'd')
		printf("%ld %d died\n", current_time, philo_num);
}

long	ft_gettime(t_var *vars)
{
	struct timeval	tmv;

	if (gettimeofday(&tmv, NULL) == -1)
		ft_error("current_time error");
	return (tmv.tv_sec * 1000 + tmv.tv_usec / 1000 - vars->begin_time);
}

void	ft_error(char *str)
{
	printf("Error: %s\n", str);
	exit(1);
}

void	ft_full_detector(t_var *vars)
{
	unsigned int	i;

	i = 1;
	if (vars->nb_of_times_each_philo_must_eat == 0)
		return ;
	while (i <= vars->nb_of_philos)
	{
		if (vars->nb_of_eating[i] < vars->nb_of_times_each_philo_must_eat)
			return ;
		i++;
	}
	write(1, "every philosopher have had enough\n", 36);
	exit(0);
}
