
#include "philo.h"

int	is_full(t_philo *ph)
{
	if (ph->data->param->nbr_of_time_must_eat > 0 &&
		ph->nbr_eat >= ph->data->param->nbr_of_time_must_eat)
		return (1);
	return (0);
}

int	is_will_run(t_philo *ph)
{
	if (is_dead (ph))
		return (0);
	if (is_full (ph))
		return (0);
	return (1);
}

void	let_sleep (int sleep_time, t_data *data)
{
	int	time;

	time = get_time ();
	while (get_time() - time < sleep_time)
	{
		pthread_mutex_lock (&data->stop);
		if (data->dead)
		{
			pthread_mutex_unlock (&data->stop);
			break ;
		}
		pthread_mutex_unlock (&data->stop);
		usleep (100);
	}
}
