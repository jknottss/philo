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
#include "philo.h"

int	ft_start_and_check(pthread_t *thread, t_philo *philo, \
pthread_mutex_t *print_mut, pthread_mutex_t *dead_mut)
{
	int	i;
	int	nums_philo;

	nums_philo = *philo[0].data_arr[num_of_philos];
	i = 0;
	ft_usleep(1);
	while (i < nums_philo)
	{
		philo[i].last_eating = 0;
		pthread_create(&thread[i], 0, ft_philo, &philo[i]);
		pthread_detach(thread[i]);
		i++;
	}
	i = 1;
	while (1)
	{
		while (i)
			i = ft_is_dead(philo, dead_mut, print_mut);
		return (1);
	}
}

int	ft_init_app(int *data, int nums_philos, pthread_t *thread)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_mut;
	pthread_mutex_t	print_mut;
	int				app;

	pthread_mutex_init(&dead_mut, 0);
	pthread_mutex_init(&print_mut, 0);
	philo = init_philos(data, nums_philos, &dead_mut, &print_mut);
	forks = init_forks(philo, nums_philos);
	app = ft_start_and_check(thread, philo, &print_mut, &dead_mut);
	return (app);
}

t_philo	*init_philos(int *data, int num_philos, pthread_mutex_t *dead_mut, \
pthread_mutex_t *print_mut)
{
	t_philo			*philos;
	int				i;
	long			time;

	i = 0;
	philos = (t_philo *) malloc(sizeof (t_philo) * num_philos);
	if (philos == NULL)
		return (philos);
	time = ft_set_start_time();
	while (i < num_philos)
	{
		philos[i].data_arr[num_of_philos] = &data[num_of_philos];
		philos[i].data_arr[time_to_die] = &data[time_to_die];
		philos[i].data_arr[time_to_eat] = &data[time_to_eat];
		philos[i].data_arr[time_to_sleep] = &data[time_to_sleep];
		philos[i].data_arr[must_eat] = &data[must_eat];
		philos[i].philo_nbr = i + 1;
		philos[i].start_prog = time;
		philos[i].dead_mut = dead_mut;
		philos[i].print_mut = print_mut;
		philos[i].eat_count = 0;
		i++;
	}
	return (philos);
}

pthread_mutex_t	*init_forks(t_philo *philos, int nums_philos)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *) \
			malloc(sizeof (pthread_mutex_t) * nums_philos);
	if (forks == NULL)
		return (NULL);
	i = 0;
	while (i < nums_philos)
	{
		pthread_mutex_init(&forks[i], 0);
		philos[i].right_fork = i;
		philos[i].left_fork = (i + 1) % nums_philos;
		philos[i].forks = forks;
		i++;
	}
	return (forks);
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
