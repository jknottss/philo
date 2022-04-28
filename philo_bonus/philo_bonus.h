/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <signal.h>

typedef struct s_philo {
	long			start_prog;
	long			last_eating;
	int				*data_arr[5];
	int				eat_count;
	int				philo_nbr;
	int				left_fork;
	int				right_fork;
	int				*pid;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*dead;
	sem_t			*proc;
	int				full;
}	t_philo;

enum e_philo_data {
	num_of_philos,
	time_to_die,
	time_to_eat,
	time_to_sleep,
	must_eat,
};
int				ft_atoi(char *str);
int				ft_dead_philo_check(t_philo philo);
int				ft_is_dead(t_philo *philo);
int				ft_is_full(t_philo *philo);
t_philo			*ft_init_app(int *data);
t_philo			ft_start_and_check(t_philo *philo);
t_philo			*init_philos(int *data);
int				*init_data(int argc, char **argv);
void			ft_usleep(int sleep_time);
long			ft_set_start_time(void);
void			ft_philo(t_philo *philo);
void			ft_eat(t_philo *philo);
void			ft_take_fork(t_philo *philo);
void			*ft_check(void *data);
int				ft_dead_check(t_philo *philo);
int				ft_full(t_philo *philo);
void			ft_exit(t_philo *philo);
#endif
