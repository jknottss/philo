/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char **argv)
{
	pthread_t	*thread;
	int			*data;
	int			nums_philos;
	int			app;

	app = 0;
	if (argc == 5 || argc == 6)
		data = init_data(argc, argv);
	else
		return (1);
	nums_philos = ft_atoi(argv[1]);
	thread = (pthread_t *) malloc(sizeof (pthread_t) * nums_philos);
	if (thread == NULL)
		return (1);
	app = ft_init_app(data, nums_philos, thread);
	if (app == 1)
	{
		free(thread);
		free(data);
		return (1);
	}
	return (0);
}
