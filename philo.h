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
    long long last_eat;
    struct s_params *params;
    pthread_mutex_t mutex;
}              t_philo;

typedef struct s_params
{
    int philo_num;
    int die_time;
    int eat_time;
    int sleep_time;
    int at_last_eat;
    long long start;
    int end;
    t_philo *philo;
    pthread_mutex_t *forks;
    pthread_mutex_t message;
    pthread_mutex_t is_dead;


}              t_params;

long	ft_atoi(const char *str);
//int ft_initilize_params(t_params *params, int argc, char **argv);
//int ft_initilize_philo(t_params  *params);
//int ft_initilize_mutex(t_params *params);
int ft_initilize(t_params *params, int argc, char **argv);
void ft_destroy(t_params *params);
long long ft_get_time(void);
void ft_printik(t_philo *philo, char *str);
int ft_is_digit(char *s);
#endif