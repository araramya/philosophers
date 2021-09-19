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
    if(params->philo)
    {
        i = 0;
        while(i < params->philo_num)
            pthread_mutex_destroy(&params->philo[i++].mutex);
        free(params->philo);
    }
    
}

long long ft_get_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000); //why ?
}