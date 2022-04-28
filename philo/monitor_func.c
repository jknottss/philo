/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_is_full(t_philo *philo)
{
	if (philo->eat_count == 0)
	{
		philo->full = -1;
		return (1);
	}
	return (0);
}

int	ft_dead_philo_check(t_philo philo, pthread_mutex_t *dead_mut, \
pthread_mutex_t *print_mut)
{
	long	current;

	pthread_mutex_lock(dead_mut);
	current = ft_set_start_time();
	if ((current - philo.last_eating) > *philo.data_arr[time_to_die])
	{
		printf("%ld %d died\n", current - philo.start_prog, philo.philo_nbr);
		pthread_mutex_lock(print_mut);
		return (-1);
	}
	else
		pthread_mutex_unlock(dead_mut);
	return (0);
}

int	ft_is_dead(t_philo *philo, pthread_mutex_t *dead_mut, \
pthread_mutex_t *print_mut)
{
	int				i;
	int				is_dead;
	int				full;
	int				philo_nbr;

	full = 0;
	i = 0;
	philo_nbr = *philo[0].data_arr[num_of_philos];
	while (1)
	{
		if (i == philo_nbr)
			i = 0;
		is_dead = ft_dead_philo_check(philo[i], dead_mut, print_mut);
		if (is_dead == -1)
			return (0);
		pthread_mutex_lock(dead_mut);
		if (*philo[i].data_arr[must_eat] != -1 && philo[i].full == 0)
			full += ft_is_full(&philo[i]);
		if (full == philo_nbr)
			return (0);
		pthread_mutex_unlock(dead_mut);
		pthread_mutex_unlock(print_mut);
		i++;
	}
	return (1);
}
