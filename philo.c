#include "philo.h"
void print_params(t_params *params)
{
    printf("philo_num_______%d\n", params->philo_num);
    printf("die_time_______%d\n", params->die_time);
    printf("eat_time________%d\n", params->eat_time);
    printf("sleep_time_______%d\n", params->sleep_time);
    printf("at_last_eat_______%d\n", params->at_last_eat);
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