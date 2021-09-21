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

int ft_is_digit(char *s)
{
    int i;
    i = 0;
    while(s[i])
    {
        if(s[i] < '0' || s[i] > '9')
            return (1);
        i++;
    }
    return (0);
}

long long ft_get_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    //printf("get_time \n");
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000); //why ?
}

void ft_printik(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->params->message);
    printf("%lld %d %s\n", (ft_get_time() - philo->params->start), philo->index, str);
    if(*str != 'd')
        pthread_mutex_unlock(&philo->params->message);
}