#include "philo.h"


int ft_initilize_params(t_params *params, int argc, char **argv)
{
    if(argc == 6)
        params->at_last_eat = ft_atoi(argv[5]);
    else
        params->at_last_eat = -1;
    params->philo_num = ft_atoi(argv[1]);
    params->die_time = ft_atoi(argv[2]);
    params->eat_time = ft_atoi(argv[3]);
    params->sleep_time = ft_atoi(argv[4]);
    params->philo = NULL;
    params->forks = NULL;
    params->end = 0;
    params->start = 0;
    params->philo = malloc(sizeof(t_philo) * params->philo_num);
     if(!(params->philo))
    {
        printf("ERROR! :malloc params->philo failed:\n");
        return (1);
    }
    return (0);    
}

int ft_initilize_philo(t_params  *params)
{
    int i;
    i = 0;
    while (i < params -> philo_num)
    {
        params->philo[i].left_fork = i;
        params->philo[i].right_fork = (i + 1) % params->philo_num;
        params->philo[i].eat_c = 0;
        params->philo[i].params = params;
        pthread_mutex_init(&params->philo[i].mutex, NULL);
        i++;
    }
    return (0);
}  

int ft_initilize_mutex(t_params *params)
{
    int i;

    i = 0;
    params->forks = malloc(sizeof(pthread_mutex_t) * params->philo_num);
    if(!params->forks)
    {
        printf("ERROR! :mutex malloc:\n");
        return (1);
    }
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