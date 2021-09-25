/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 23:00:10 by araramya          #+#    #+#             */
/*   Updated: 2021/09/22 23:00:40 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_lav_mard_er(void *philo)
{
	t_philo		*philip;
	long long	time;

	philip = (t_philo *)philo;
	while (1 && philip->eat_c != philip->params->at_last_eat)
	{
		pthread_mutex_lock(&philip->mutex);
		time = ft_get_time() - philip->last_eat;
		if (time > philip->params->die_time)
		{
			ft_printik(philip, "DIED :(");
			ft_destroy(philip->params);
			pthread_mutex_unlock(&philip->params->is_dead);
			return ((void *)0);
		}
		usleep(1000);
		pthread_mutex_unlock(&philip->mutex);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->params->forks[philo->right_fork]);
	philo->last_eat = ft_get_time();
	ft_printik(philo, "HAS TAKEN A FORK!");
	ft_printik(philo, "IS EATING YUMMI)");
	usleep(philo->params->eat_time * 1000);
	philo->eat_c++;
	pthread_mutex_unlock(&philo->params->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->params->forks[philo->right_fork]);
}

void	ft_sleep_and_think(t_philo *philo)
{
	ft_printik(philo, "IS SLEEPING zZzZ...");
	usleep(philo->params->sleep_time * 1000);
	ft_printik(philo, "IS THINKING &^#@$");
}

void	*ft_philo_do(void *philo)
{
	pthread_t	tid;
	t_philo		*philip;

	philip = (t_philo *)philo;
	if (pthread_create(&tid, NULL, &ft_lav_mard_er, philo))
		return ((void *)1 );
	pthread_detach(tid);
	while (1 && philip->eat_c != philip->params->at_last_eat)
	{
		ft_eat(philip);
		ft_sleep_and_think(philip);
		if (philip->eat_c == philip->params->at_last_eat)
			philip->params->end++;
	}
	if (philip->params->end == philip->params->philo_num)
	{
		printf("SPAGETTI WAS DELICIOS :)");
		ft_destroy(philip->params);
		pthread_mutex_unlock(&philip->params->is_dead);
	}
	return ((void *) 0);
}

int	ft_create_threads(t_params *params)
{
	int			i;
	t_philo		*philip;
	pthread_t	tid;

	i = 0;
	philip = params->philo;
	philip->params->start = ft_get_time();
	while (i < params->philo_num)
	{
		philip[i].last_eat = ft_get_time();
		if (pthread_create(&tid, NULL, &ft_philo_do, &(philip[i])))
			return (1);
		pthread_detach(tid);
		i++;
	}
	return (0);
}
