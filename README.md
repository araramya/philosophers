# philosophers

 this project, you will learn the basics of threading a process. You willlearn how to make threads. You will discover the mutex.

First of all we need to initilize our parameters, our philos and our mutexes.
I created two structures one of them is params:
```
typedef struct s_params
{
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				at_last_eat;
	long long		start;
	int				end;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message;
	pthread_mutex_t	is_dead;
}					t_params;

```
and the second is our philos 
```
typedef struct s_philo
{
	int				left_fork;
	int				right_fork;
	int				index;
	int				eat_c;
	long long		last_eat;
	struct s_params	*params;
	pthread_mutex_t	mutex;
}					t_philo;
```

1) First initilize params get them values form argv, be smart use ft_atoi .

2) second initilize your philos:

   index start with 1 
   left fork is i;
   right fork is (i + 1) % philo_num ; why ? becouse across  the round table.
   
   
3) Now you need to initilize your mutexes, for that just use `pthread_mutex_init( )` function. Why we use mutex ? We are working with threads, to somehow controll them we must use mutex. If you don't know what is mutex, read about it.
After initilizing mutex I locked `is_dead` it will be unlocked when someone will die.

4) After initilizing you need create threads . Remember each philoo must be thread.

5) Also we will create some thread, that will monitor each philo and if someone is dead it will stop our simulation.

6) And then of corse you need some functions that provide eating sleeping and thinking.

That's it. I didn't like this project :( but if you have some questions I will wait. arsen.aramyan2001@gmail.com

