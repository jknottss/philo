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
#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	int			*data;
	t_philo		*philo;

	if (argc == 5 || argc == 6)
		data = init_data(argc, argv);
	else
		return (1);
	philo = ft_init_app(data);
	sem_wait(philo->proc);
	ft_exit(philo);
	free(data);
	free(philo->pid);
	return (0);
}
