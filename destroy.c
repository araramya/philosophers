#include "philo.h"

void ft_destroy(t_params *params)
{
    int i;

    if(params->forks)
    {
        i = 0;
        while (i < params->philo_num)
            pthread_mutex_destroy(&params->forks[i++]);
        free(params->forks);
    }
    
}