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
        if(time > philip->params->die_time)
        {
             ft_printik(philip, "DIED :(");///!!!!!!!!!!!!!!!!!!!!!PRINT STATUS _NEED_A_FUNCTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            ft_destroy(philip->params);
            pthread_mutex_unlock(&philip->params->is_dead);
            return ((void *)0);
        }
        usleep(1000);
        pthread_mutex_unlock(&philip->mutex);
    }
    return (NULL);
}

void ft_eat(t_philo *philo)
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

void ft_sleep_and_think(t_philo *philo)
{
    ft_printik(philo, "IS SLEEPING zZzZ...");
    usleep(philo->params->sleep_time * 1000);
    ft_printik(philo, "IS THINKING &^#@$");

}

void *ft_philo_do(void *philo)
{
    pthread_t tid;
    t_philo *philip;
    philip = (t_philo *)philo;
    if(pthread_create(&tid, NULL, &ft_lav_mard_er, philo))
        return ((void *)1 );
    pthread_detach(tid);

    while(1 && philip->eat_c != philip->params->at_last_eat)
    {
        ft_eat(philip);
        ft_sleep_and_think(philip);
        if(philip->eat_c == philip->params->at_last_eat)
         philip->params->end++;
    }
    if(philip->params->end == philip->params->philo_num)
    {
        printf("SPAGETTI WAS DELICOS :)");
        ft_destroy(philip->params);
        pthread_mutex_unlock(&philip->params->is_dead);
    }
    return ((void *) 0);
}

int ft_create_threads(t_params *params)
{
    int i;
    t_philo *philip;
    pthread_t tid;

    i = 0;
    philip = params->philo;
    philip->params->start = ft_get_time();
    //printf("THREADS WAS DONE !\n");
    while(i<params->philo_num)
    {
        philip[i].last_eat = ft_get_time();
        if(pthread_create(&tid, NULL, &ft_philo_do, &(philip[i])))
            return (1);
        pthread_detach(tid);
        i++;
    }
    return(0);


}
int main(int argc, char **argv)
{
    t_params *params;
    if(argc != 5 && argc != 6)
        {
            printf("ERROR :ARGUMENTS COUNT IS WRONG :\n");
            return (1);
        }
    printf("hi\n");
    if(ft_atoi(argv[1]) == 1)
        {
            printf("0 1 DEAD :(\n");
            return (0);
        }
    params = malloc(sizeof(t_params));
    if(!params)
        return (1);
    if(ft_initilize(params, argc, argv))
        {
            ft_destroy(params);
            return (1);
        }
    if(ft_create_threads(params))
        {
            ft_destroy(params);
            return (1);
        }
    pthread_mutex_lock(&(params->is_dead));
    return (0);

    // if(argc == 5 || argc == 6)
    // {
    //     t_params *params;
    //     if(ft_atoi(argv[1]) == 1)
    //     {
    //         printf("0 1 DEAD :(\n");
    //         return (0);
    //     }
    //     params = malloc(sizeof(t_params));
    //     if(!params)
    //     {
    //         printf("ERROR!  :malloc params failed: \n");
    //         return(1);
    //     }
    //     if(ft_initilize(params, argc, argv))
    //         {
    //             printf("ERROR! :Initalization failed:");
    //             //destroy mutexnery u free mallocs need a functon !DONE!
    //             ft_destroy(params);
    //             return (1);
    //         }
    //    // printf("NONONO\n");
    //     if(ft_create_treads(params))
    //     {
    //         printf("ERROR! :Creation threads:\n");
    //         ft_destroy(params);
    //         return (1);
    //     }
    //     pthread_mutex_lock(&(params->is_dead));
    //      //   print_params(params);
    // }


    // else
    // {
    //     printf ("ERROR! :Wrong Number of arguments: \n");
    //     return (1);
    // }   
}