/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

t_philo	ft_start_and_check(t_philo *philo)
{
	int	i;
	int	nums_philo;
	int	*pids;

	nums_philo = *philo->data_arr[num_of_philos];
	pids = malloc(sizeof (int) * nums_philo);
	i = 0;
	philo->pid = pids;
	philo->last_eating = 0;
	while (i < nums_philo)
	{
		philo->philo_nbr = i + 1;
		pids[i] = fork();
		if (pids[i] == 0)
			ft_philo(philo);
		i++;
		ft_usleep(100);
	}
	sem_wait(philo->proc);
	return (*philo);
}

void	init_sem(t_philo *philo)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("dead");
	sem_unlink("proc");
	philo->proc = sem_open("proc", O_CREAT, 0600, 1);
	philo->forks = sem_open("forks", O_CREAT, 0600, \
	*philo->data_arr[num_of_philos]);
	philo->print = sem_open("print", O_CREAT, 0600, 1);
	philo->dead = sem_open("dead", O_CREAT, 0600, 1);
}

t_philo	*ft_init_app(int *data)
{
	t_philo			*philo;

	philo = init_philos(data);
	init_sem(philo);
	*philo = ft_start_and_check(philo);
	return (philo);
}

t_philo	*init_philos(int *data)
{
	t_philo			*philo;
	long			time;

	philo = malloc(sizeof (t_philo));
	if (philo == NULL)
		return (philo);
	time = ft_set_start_time();
	philo->data_arr[num_of_philos] = &data[num_of_philos];
	philo->data_arr[time_to_die] = &data[time_to_die];
	philo->data_arr[time_to_eat] = &data[time_to_eat];
	philo->data_arr[time_to_sleep] = &data[time_to_sleep];
	philo->data_arr[must_eat] = &data[must_eat];
	philo->start_prog = time;
	philo->eat_count = data[must_eat];
	philo->full = 0;
	return (philo);
}

int	*init_data(int argc, char **argv)
{
	int	*data_arr;

	data_arr = malloc(sizeof (int) * 5);
	if (data_arr == NULL)
		return (data_arr);
	if (argc == 6)
		data_arr[must_eat] = ft_atoi(argv[5]);
	else
		data_arr[must_eat] = -1;
	data_arr[num_of_philos] = ft_atoi(argv[1]);
	data_arr[time_to_die] = ft_atoi(argv[2]);
	data_arr[time_to_eat] = ft_atoi(argv[3]);
	data_arr[time_to_sleep] = ft_atoi(argv[4]);
	return (data_arr);
}
