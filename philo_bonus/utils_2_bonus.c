/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_exit(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < *philo->data_arr[num_of_philos])
	{
		kill(philo->pid[i], SIGKILL);
		i++;
	}
	sem_close(philo->forks);
	sem_close(philo->print);
	sem_close(philo->dead);
	sem_close(philo->proc);
	free(philo);
}
