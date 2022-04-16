/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo {
	long			start_prog;
	long			last_eating;
	int				*data_arr[5];
	int				eat_count;
	int				philo_nbr;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*dead_mut;
	pthread_mutex_t	*print_mut;
	int				left_fork;
	int				right_fork;
}	t_philo;

enum e_philo_data {
	num_of_philos,
	time_to_die,
	time_to_eat,
	time_to_sleep,
	must_eat,
};
int				ft_atoi(char *str);
int				ft_dead_philo_check(t_philo philo, pthread_mutex_t *dead_mut, \
pthread_mutex_t *print_mut);
int				ft_is_dead(t_philo *philo, pthread_mutex_t *dead_mut, \
pthread_mutex_t *print_mut);
int				ft_is_full(t_philo philo, int full, pthread_mutex_t *print_mut);
int				ft_init_app(int *data, int nums_philos, pthread_t *thread);
int				ft_start_and_check(pthread_t *thread, t_philo *philo, \
pthread_mutex_t *print_mut, pthread_mutex_t *dead_mut);
pthread_mutex_t	*init_forks(t_philo *philos, int nums_philos);
t_philo			*init_philos(int *data, int num_philos, \
pthread_mutex_t *dead_mut, pthread_mutex_t *print_mut);
int				*init_data(int argc, char **argv);
void			ft_usleep(int sleep_time);
long			ft_set_start_time(void);
void			*ft_philo(void *data);
void			ft_eat(t_philo *philo);
void			ft_take_fork(t_philo *philo);
void			ft_put_fork(t_philo *philo);
#endif
