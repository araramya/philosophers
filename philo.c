/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:11:58 by araramya          #+#    #+#             */
/*   Updated: 2021/09/22 22:58:53 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	for_mulya(t_params *params, int argc, char **argv)
{
	if (ft_initilize(params, argc, argv))
	{
		ft_destroy(params);
		return (1);
	}
	if (ft_create_threads(params))
	{
		ft_destroy(params);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	*params;

	if (argc != 5 && argc != 6)
	{
		printf ("ERROR! :Wrong Number of arguments: \n");
		return (1);
	}
	if (ft_atoi(argv[1]) == 1)
	{
		printf("0 1 DEAD :(\n");
		return (0);
	}
	params = malloc(sizeof(t_params));
	if (!params)
		return (1);
	if (for_mulya(params, argc, argv))
		return (1);
	pthread_mutex_lock(&(params->is_dead));
	free(params);
	return (0);
}
