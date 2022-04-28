/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_start(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int		res;
	int		start;

	res = 0;
	start = ft_start(str);
	if (str[start] == '-' || !((str[start] > 47 && str[start] < 58)))
	{
		printf("incorrect input\n");
		exit(1);
	}
	while (str[start] > 47 && str[start] < 58)
	{
		res = (res * 10) + (str[start] - '0');
		start++;
		if (str[start] != '\0' && !((str[start] > 47 && str[start] < 58)))
		{
			printf("incorrect input\n");
			return (-1);
		}
	}
	return (res);
}

void	ft_usleep(int sleep_time)
{
	struct timeval	now;
	struct timeval	time;
	int				res;

	res = gettimeofday(&now, 0);
	res = gettimeofday(&time, 0);
	while ((time.tv_sec - now.tv_sec) * 1000 + \
	(time.tv_usec - now.tv_usec) / 1000 < sleep_time)
	{
		usleep(165);
		res = gettimeofday(&time, 0);
	}
}

long	ft_set_start_time(void)
{
	struct timeval	start;
	long			res;

	res = gettimeofday(&start, 0);
	res = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (res);
}
