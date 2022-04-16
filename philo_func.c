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
#include "philo.h"

void	*ft_philo(void *data)
{
	t_philo			*philo;
	long			time;

	philo = (t_philo *) data;
	if (philo->philo_nbr % 2 == 0)
		ft_usleep(10);
	while (1)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		ft_put_fork(philo);
		time = ft_set_start_time();
		printf("%ld %d is sleeping\n", time - philo->start_prog, \
	philo->philo_nbr);
		ft_usleep(*(philo)->data_arr[time_to_sleep]);
		time = ft_set_start_time();
		pthread_mutex_lock(philo->print_mut);
		printf("%ld %d is thinking\n", time - philo->start_prog, \
	philo->philo_nbr);
		pthread_mutex_unlock(philo->print_mut);
	}
	return (0);
}

void	ft_eat(t_philo *philo)
{
	int				res;
	struct timeval	eating;
	long			current;

	current = ft_set_start_time();
	pthread_mutex_lock(philo->print_mut);
	pthread_mutex_lock(philo->dead_mut);
	printf("%ld %d is eating\n", current - philo->start_prog, philo->philo_nbr);
	pthread_mutex_unlock(philo->print_mut);
	res = gettimeofday(&eating, 0);
	philo->last_eating = ((eating.tv_sec * 1000) + \
			(eating.tv_usec / 1000));
	philo->eat_count++;
	pthread_mutex_unlock(philo->dead_mut);
	ft_usleep(*(philo)->data_arr[time_to_eat]);
}

void	ft_take_fork(t_philo *philo)
{
	long			current_time;
	struct timeval	time;

	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(&philo->forks[philo->right_fork]);
		pthread_mutex_lock(&philo->forks[philo->left_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->forks[philo->right_fork]);
	}
	current_time = gettimeofday(&time, 0);
	current_time = ((time.tv_sec * 1000) + \
			(time.tv_usec / 1000));
	pthread_mutex_lock(philo->print_mut);
	printf("%ld %d has taken a fork\n", current_time - philo->start_prog, \
	philo->philo_nbr);
	pthread_mutex_unlock(philo->print_mut);
}

void	ft_put_fork(t_philo *philo)
{
	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_unlock(&philo->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->forks[philo->right_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->forks[philo->left_fork]);
	}
}
