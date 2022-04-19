/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:47:15 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/20 13:02:05 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define FORK 0
# define MNT 1
# define CNT 0
# define STMP 1

typedef struct s_var
{
	long			nb_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nb_of_times_each_philo_must_eat;

	pthread_mutex_t	**mutex_id;
	pthread_mutex_t	exit_mutex_id;
	pthread_t		*th_id;
	pthread_t		s_monitor_id;
	pthread_t		f_monitor_id;
	long			*fork;
	long			*nb_of_eating;
	long			*last_eating_time;
	long			begin_time;
	long			simul_switch;
	long			error_flag;
	long			main_spin;
}	t_var;

void	ft_init(char **argv, t_var *vars);
long	ft_arginit(char **argv, t_var *vars);
long	ft_meminit(t_var *vars);
long	ft_memerror_check(t_var *vars);
void	ft_zeroinit(t_var *vars);

void	ft_simulation_init(t_var *vars);
long	ft_mutex_init(t_var *vars);
long	ft_th_init(t_var *vars);
void	ft_simul_on(t_var *vars);

void	*ft_routine(void *arg);
void	ft_eat(long philo_num, long former_philo_num, t_var *vars);
void	ft_sleep_think(long philo_num, t_var *vars);
void	*ft_s_monitor(void *arg);
void	*ft_f_monitor(void *arg);

void	ft_eatstamp(long philo_num, t_var *vars);
void	ft_forkstamp(long philo_numm, t_var *vars);
void	ft_sleepstamp(long philo_num, t_var *vars);
void	ft_deathstamp(long philo_num, t_var *vars);
void	ft_fullstamp(t_var *vars);

long	ft_atol(char *str);
void	ft_error(char *str, t_var *vars, long flag);
long	ft_gettime(t_var *vars);
void	ft_wait(long time_amount, t_var *vars);
void	ft_spin(t_var *vars);

#endif