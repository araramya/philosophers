#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include "libft.h"

typedef struct s_args
{
    int philo_num;
    int die_time;
    int eat_time;
    int sleep_time;
    int must_eat_count;

}              t_args;

int ft_init_args(int argc, char **argv, t_args *args)
{
    if(argc == 6)
    {
        args->must_eat_count = ft_atoi(argv[5]);
    }
    args->philo_num = ft_atoi(argv[1]);
    args->die_time = ft_atoi(argv[2]);
    args->eat_time = ft_atoi(argv[3]);
    args->sleep_time = ft_atoi(argv[4]);
}

int main(int argc, char **argv )
{
    if(argc == 5 || argc == 6)
    {
            //bla bla bla
        t_args *args ;
        ft_init_args(argc, argv, args);

    }
    else
    {
        printf("ERROR! Wrong arguments.\n)");
    }

}