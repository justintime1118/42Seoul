/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:38:47 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/08 20:34:13 by jiyoo            ###   ########.fr       */
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
	return (vars);
}

int	ft_check_ovf(unsigned int nbr, unsigned int tmp)
{
	if (nbr < tmp)
		return (1);
	else
		return (0);
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	nbr;
	unsigned int	tmp;

	nbr = 0;
	tmp = 0;
	if (str == 0 || !*str || *str < '0' || '9' < *str)
		ft_error("atoi parameter error");
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			ft_error("atoi parameter error");
		nbr *= 10;
		nbr += *str - '0';
		str++;
		if (ft_check_ovf(nbr, tmp) == 1)
			ft_error("atoi overflow error");
		tmp = nbr;
	}
	return (nbr);
}
