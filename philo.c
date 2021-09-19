#include "philo.h"
void print_params(t_params *params)
{
    printf("philo_num_______%d\n", params->philo_num);
    printf("die_time_______%d\n", params->die_time);
    printf("eat_time________%d\n", params->eat_time);
    printf("sleep_time_______%d\n", params->sleep_time);
    printf("at_last_eat_______%d\n", params->at_last_eat);
}
void *ft_lav_mard_er(void *philo)
{
    t_philo *philip;
    long long time;

    philip = (t_philo *)philo;
    while(1 && philip->eat_c != philip->params->at_last_eat)
    {
        pthread_mutex_lock(&philip->mutex);
        time = ft_get_time() - philip->last_eat;
        if(time > philip->params->die_time);
        {
            //!!!!!!!!!!!!!!!!!!!!!PRINT STATUS _NEED_A_FUNCTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            ft_destroy(philip->params);
            pthread_mutex_unlock(&philip->params->is_dead);
            return ((void *)0);
        }
        usleep(100);
        pthread_mutex_unlock(&philip->mutex);
    }
}       


void *ft_philo_do(void *philo)
{
    pthread_t tid;
    t_philo *philip;
    philip = (t_philo *)philo;
    if(pthread_create(&tid, NULL, &ft_lav_mard_er, philo))
}

int ft_create_treads(t_params *params)
{
    int i;
    t_philo *philo;
    pthread_t tid;

    i = 0;
    philo = params->philo;
    philo->params->start = ft_get_time();
    if(ptread_creat(&tid, NULL, &ft_philo_do, &philo[i]))

}
int main(int argc, char **argv)
{
    if(argc == 5 || argc == 6)
    {
        t_params *params;
        params = malloc(sizeof(t_params));
        if(!params)
        {
            printf("ERROR!  :malloc params failed: \n");
            return(1);
        }
        if(ft_initilize_params(params, argc, argv) || ft_initilize_philo(params)
            || ft_initilize_mutex(params))
            {
                printf("ERROR! :Initalization failed:");
                //destroy mutexnery u free mallocs need a functon
                ft_destroy(params);
                return (1);
            }
            print_params(params);
    }

    else
    {
        printf ("ERROR! :Wrong Number of arguments: \n");
        return (1);
    }   
}