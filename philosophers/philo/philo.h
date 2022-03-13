/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:47:15 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/11 16:56:50 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_var
{
	unsigned int	nb_of_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	nb_of_times_each_philo_must_eat;

	pthread_mutex_t	*mutex_id;
	pthread_t		*th_id;
	pthread_t		monitor_id;
	int				*fork;
	unsigned int	*nb_of_eating;
	long			*last_eating_time;
	long			begin_time;
}	t_var;

t_var			*ft_init(char **argv);
void			ft_simulation_init(t_var *vars);
void			ft_zeroinit(t_var *vars);
unsigned int	ft_atoi(char *str);

void			ft_eat(int philo_num, int former_philo_num, t_var *vars);
void			ft_sleep(int philo_num, t_var *vars, char flag);
void			*ft_routine(void *arg);
void			*ft_monitor(void *arg);

void			ft_timestamp(int philo_num, char flag, t_var *vars);
long			ft_gettime(t_var *vars);
void			ft_error(char *str);
void			ft_full_detector(t_var *vars);

#endif