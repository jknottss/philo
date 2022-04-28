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
#include "philo_bonus.h"

int	ft_is_full(t_philo *philo)
{
	if (philo->eat_count <= 0)
	{
		philo->full = -1;
		return (1);
	}
	return (0);
}

int	ft_dead_check(t_philo *philo)
{
	long	current;
	long	last;
	int		time_to_d;

	sem_wait(philo->dead);
	current = ft_set_start_time();
	last = philo->last_eating;
	time_to_d = *philo->data_arr[time_to_die];
	if ((current - last) > time_to_d)
	{
		sem_wait(philo->print);
		printf("%ld %d died\n", current - philo->start_prog, philo->philo_nbr);
		return (1);
	}
	sem_post(philo->dead);
	return (0);
}

int	ft_full(t_philo *philo)
{
	int	full;

	full = 0;
	sem_wait(philo->dead);
	if (*philo->data_arr[must_eat] != -1 && philo->full == 0)
		full = ft_is_full(philo);
	if (full)
	{
		return (1);
	}
	sem_post(philo->dead);
	return (0);
}

void	*ft_check(void *data)
{
	t_philo	*philo;
	int		sleep_time;
	int		last_philo;

	philo = (t_philo *) data;
	sleep_time = *philo->data_arr[time_to_die];
	ft_usleep(sleep_time);
	last_philo = *philo->data_arr[num_of_philos];
	while (1)
	{
		if (ft_dead_check(philo))
		{
			sem_post(philo->proc);
			exit(0);
		}
		if (philo->philo_nbr == last_philo)
		{
			if (ft_full(philo))
			{
				sem_post(philo->proc);
				exit(0);
			}
		}
	}
	return (0);
}
