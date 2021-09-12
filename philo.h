#ifndef PHILO_H
#define PHILO_H


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdlib.h>


typedef struct s_philo
{
    int left_fork;
    int right_fork;
    int index;
    int eat_c;
   // struct s_params *params;
    pthread_mutex_t mutex;
}              t_philo;

typedef struct s_params
{
    int philo_num;
    int die_time;
    int eat_time;
    int sleep_time;
    int at_last_eat;
    t_philo *philo;
    pthread_mutex_t *forks;

}              t_params;

long	ft_atoi(const char *str);
int ft_initilize_params(t_params *params, int argc, char **argv);

int ft_initilize_philo(t_params  *params);
int ft_initilize_mutex(t_params *params);

#endif