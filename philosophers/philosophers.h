#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_params
{
    int             n;
    long            time_to_die;
    long            time_to_eat;
    long            time_to_sleep;
    int             must_eat;
    int             all_must_eat;
    int             simulation_end;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
    pthread_mutex_t meal_mutex;
    long            *last_meal;
    int             *eat_count;
    long            start_time;
    pthread_mutex_t simulation_mutex;
}   t_params;

typedef struct s_philo
{
    int         id;
    pthread_t   thread;
    t_params    *p;
}   t_philo;

long    time_ms(void);
void    smart_sleep(long ms, t_params *p);
void    print_action(t_params *p, int id, const char *action);
void    take_forks(t_philo *ph);
void    drop_forks(t_philo *ph);
void    *philo_routine(void *arg);
void    *monitor_routine(void *arg);

#endif
