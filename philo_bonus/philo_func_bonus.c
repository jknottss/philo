/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

void	ft_philo(t_philo *philo)
{
	long			time;
	pthread_t		pthread;

	if (philo->philo_nbr % 2 == 0)
		ft_usleep(10);
	pthread_create(&pthread, 0, ft_check, philo);
	pthread_detach(pthread);
	while (1)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		time = ft_set_start_time();
		sem_wait(philo->print);
		printf("%ld %d is sleeping\n", time - philo->start_prog, \
	philo->philo_nbr);
		sem_post(philo->print);
		ft_usleep(*(philo)->data_arr[time_to_sleep]);
		time = ft_set_start_time();
		sem_wait(philo->print);
		printf("%ld %d is thinking\n", time - philo->start_prog, \
	philo->philo_nbr);
		sem_post(philo->print);
	}
}

void	ft_eat(t_philo *philo)
{
	int				res;
	struct timeval	eating;
	long			current;

	sem_wait(philo->print);
	current = ft_set_start_time();
	printf("%ld %d is eating\n", current - philo->start_prog, philo->philo_nbr);
	sem_post(philo->print);
	res = gettimeofday(&eating, 0);
	philo->last_eating = ((eating.tv_sec * 1000) + \
			(eating.tv_usec / 1000));
	philo->eat_count--;
	ft_usleep(*(philo)->data_arr[time_to_eat]);
	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	ft_take_fork(t_philo *philo)
{
	long			current_time;
	struct timeval	time;

	current_time = gettimeofday(&time, 0);
	current_time = ((time.tv_sec * 1000) + \
			(time.tv_usec / 1000));
	sem_wait(philo->forks);
	sem_wait(philo->print);
	printf("%ld %d has taken a fork\n", current_time - philo->start_prog, \
	philo->philo_nbr);
	sem_post(philo->print);
	sem_wait(philo->forks);
	sem_wait(philo->print);
	printf("%ld %d has taken a fork\n", current_time - philo->start_prog, \
	philo->philo_nbr);
	sem_post(philo->print);
}
