/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:11:45 by araramya          #+#    #+#             */
/*   Updated: 2021/09/22 14:15:35 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_initilize_philos(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->philo_num)
	{
		params->philo[i].index = i + 1;
		params->philo[i].left_fork = i;
		params->philo[i].right_fork = (i + 1) % params->philo_num;
		params->philo[i].eat_c = 0;
		params->philo[i].params = params;
		pthread_mutex_init(&params->philo[i].mutex, NULL);
		i++;
	}
}

int	ft_initilize_mutex(t_params *params)
{
	int	i;

	i = 0;
	params->forks = malloc(sizeof(pthread_mutex_t) * params->philo_num);
	if (!params->forks)
		return (1);
	while (i < params->philo_num)
	{
		pthread_mutex_init(&params->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&params->message, NULL);
	pthread_mutex_init(&params->is_dead, NULL);
	pthread_mutex_lock(&params->is_dead);
	return (0);
}

int	ft_initilize(t_params *params, int argc, char **argv)
{
	int	i;

	i = 1;
	params->philo = NULL;
	params->forks = NULL;
	while (i < argc)
	{
		if (ft_is_digit(argv[i]) || ft_atoi(argv[i]) > 2147483647)
			return (1);
		i++;
	}
	params->end = 0;
	params->philo_num = ft_atoi(argv[1]);
	params->die_time = ft_atoi(argv[2]);
	params->eat_time = ft_atoi(argv[3]);
	params->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		params->at_last_eat = ft_atoi(argv[5]);
	else
		params->at_last_eat = -1;
	params->philo = malloc(sizeof(t_philo) * params->philo_num);
	if (!params->philo)
		return (1);
	ft_initilize_philos(params);
	return (ft_initilize_mutex(params));
}
