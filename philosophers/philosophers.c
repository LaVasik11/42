#include "philosophers.h"

long time_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void smart_sleep(long ms, t_params *p)
{
    long start = time_ms();
    while (!p->simulation_end)
    {
        if (time_ms() - start >= ms)
            break;
        usleep(500);
    }
}

void print_action(t_params *p, int id, const char *action)
{
    pthread_mutex_lock(&p->print_mutex);
    if (!p->simulation_end)
        printf("%ld %d %s\n", time_ms() - p->start_time, id + 1, action);
    pthread_mutex_unlock(&p->print_mutex);
}

void take_forks(t_philo *ph)
{
    t_params *p = ph->p;
    int id = ph->id;

    if (id % 2 == 0)
    {
        pthread_mutex_lock(&p->forks[id]);
        print_action(p, id, "has taken the left fork");
        pthread_mutex_lock(&p->forks[(id + 1) % p->n]);
        print_action(p, id, "has taken the right fork");
    }
    else
    {
        pthread_mutex_lock(&p->forks[(id + 1) % p->n]);
        print_action(p, id, "has taken the right fork");
        pthread_mutex_lock(&p->forks[id]);
        print_action(p, id, "has taken the left fork");
    }
}

void drop_forks(t_philo *ph)
{
    t_params *p = ph->p;
    int id = ph->id;

    pthread_mutex_unlock(&p->forks[id]);
    pthread_mutex_unlock(&p->forks[(id + 1) % p->n]);
}

void *philo_routine(void *arg)
{
    t_philo *ph = arg;
    t_params *p = ph->p;
    int id = ph->id;

    if (p->n == 1)
    {
        pthread_mutex_lock(&p->forks[0]);
        print_action(p, id, "has taken the only fork");
        smart_sleep(p->time_to_die, p);
        print_action(p, id, "died");
        return NULL;
    }

    while (!p->simulation_end)
    {
        take_forks(ph);

        pthread_mutex_lock(&p->meal_mutex);
        p->last_meal[id] = time_ms();
        p->eat_count[id]++;
        pthread_mutex_unlock(&p->meal_mutex);

        print_action(p, id, "is eating");
        smart_sleep(p->time_to_eat, p);
        drop_forks(ph);

        pthread_mutex_lock(&p->meal_mutex);
        if (p->all_must_eat && p->eat_count[id] >= p->must_eat)
        {
            pthread_mutex_unlock(&p->meal_mutex);
            break;
        }
        pthread_mutex_unlock(&p->meal_mutex);

        print_action(p, id, "is sleeping");
        smart_sleep(p->time_to_sleep, p);
        print_action(p, id, "is thinking");
    }
    return NULL;
}

void *monitor_routine(void *arg)
{
    t_params *p = arg;
    int i;
    while (!p->simulation_end)
    {
        usleep(1000);
        pthread_mutex_lock(&p->meal_mutex);
        i = 0;
        while (i < p->n)
        {
            if (time_ms() - p->last_meal[i] > p->time_to_die)
            {
                p->simulation_end = 1;
                pthread_mutex_unlock(&p->meal_mutex);
                pthread_mutex_lock(&p->print_mutex);
                printf("%ld %d died\n", time_ms() - p->start_time, i + 1);
                pthread_mutex_unlock(&p->print_mutex);
                return NULL;
            }
            i++;
        }
        if (p->all_must_eat)
        {
            int all = 1;
            for (i = 0; i < p->n; i++)
            {
                if (p->eat_count[i] < p->must_eat)
                {
                    all = 0;
                    break;
                }
            }
            if (all)
            {
                p->simulation_end = 1;
                pthread_mutex_unlock(&p->meal_mutex);
                pthread_mutex_lock(&p->print_mutex);
                printf("%ld All philosophers have eaten %d times\n",
                    time_ms() - p->start_time, p->must_eat);
                pthread_mutex_unlock(&p->print_mutex);
                return NULL;
            }
        }
        pthread_mutex_unlock(&p->meal_mutex);
    }
    return NULL;
}

int main(int ac, char **av)
{
    t_params *p;
    t_philo  *ph;
    pthread_t monitor;
    int i;

    if (ac != 5 && ac != 6)
        return printf("Usage: ./philo number_of_philosophers time_to_die "
                      "time_to_eat time_to_sleep [number_of_times_each]\n"), 1;

    p = malloc(sizeof(*p));
    p->n = atoi(av[1]);
    p->time_to_die = atol(av[2]);
    p->time_to_eat = atol(av[3]);
    p->time_to_sleep = atol(av[4]);
    p->must_eat = (ac == 6) ? atoi(av[5]) : 0;
    p->all_must_eat = (ac == 6);
    p->simulation_end = 0;
    p->forks = malloc(p->n * sizeof(pthread_mutex_t));
    p->last_meal = malloc(p->n * sizeof(long));
    p->eat_count = malloc(p->n * sizeof(int));
    memset(p->eat_count, 0, p->n * sizeof(int));

    pthread_mutex_init(&p->print_mutex, NULL);
    pthread_mutex_init(&p->meal_mutex, NULL);
    pthread_mutex_init(&p->simulation_mutex, NULL);
    for (i = 0; i < p->n; i++)
        pthread_mutex_init(&p->forks[i], NULL);

    p->start_time = time_ms();
    for (i = 0; i < p->n; i++)
        p->last_meal[i] = p->start_time;

    ph = malloc(p->n * sizeof(*ph));
    for (i = 0; i < p->n; i++)
    {
        ph[i].id = i;
        ph[i].p = p;
        pthread_create(&ph[i].thread, NULL, philo_routine, &ph[i]);
    }
    pthread_create(&monitor, NULL, monitor_routine, p);

    pthread_join(monitor, NULL);
    for (i = 0; i < p->n; i++)
        pthread_join(ph[i].thread, NULL);

    for (i = 0; i < p->n; i++)
        pthread_mutex_destroy(&p->forks[i]);
    pthread_mutex_destroy(&p->print_mutex);
    pthread_mutex_destroy(&p->meal_mutex);
    pthread_mutex_destroy(&p->simulation_mutex);
    free(p->forks);
    free(p->last_meal);
    free(p->eat_count);
    free(ph);
    free(p);
    return 0;
}


