/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:18:10 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/19 05:19:31 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *str)
{
	long	nbr;
	long	tmp;

	nbr = 0;
	tmp = 0;
	if (str == NULL || *str < '0' || '9' < *str)
		return (-1);
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			return (-1);
		nbr *= 10;
		nbr += *str - '0';
		str++;
		if (nbr < tmp)
			return (-1);
		tmp = nbr;
	}
	return (nbr);
}

void	ft_error(char *str, t_var *vars, long flag)
{
	printf("%s\n", str);
	if (flag == 0)
		vars->error_flag = 1;
	if (flag == 1)
	{
		if (pthread_mutex_unlock(&vars->exit_mutex_id) != 0)
			write(1, "mutex lock failed: fatal\n", 26);
	}
}

long	ft_gettime(t_var *vars)
{
	struct timeval	tmv;

	if (gettimeofday(&tmv, NULL) == -1)
		ft_error("gettimeofday failed\n", vars, 1);
	return (tmv.tv_sec * 1000 + tmv.tv_usec / 1000 - vars->begin_time);
}

void	ft_wait(long time_amount, t_var *vars)
{
	long	start_time;

	start_time = ft_gettime(vars);
	while (ft_gettime(vars) - start_time < time_amount)
	{
		if (usleep(500) != 0)
			ft_error("usleep error", vars, 1);
	}
}

void	ft_spin(t_var *vars)
{
	if (usleep(100) != 0)
		ft_error("usleep error", vars, 0);
}
