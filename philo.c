#include "philo.h"

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

        if(!ft_initilize_params(params, argc, argv) || !ft_initilize_philo(params)
            || !ft_initilize_mutex(params))
            return (1);
    }
    

    

}