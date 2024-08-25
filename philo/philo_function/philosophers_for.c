/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_for.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:29:47 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/21 10:29:49 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_full(t_philo *ph)
{
	if (ph->data->param->nbr_of_time_must_eat > 0
		&& ph->nbr_eat >= ph->data->param->nbr_of_time_must_eat)
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

void	let_sleep(long sleep_time, t_philo *ph)
{
	long long	time;

	time = get_time ();
	while (get_time() - time < sleep_time)
	{
		pthread_mutex_lock (&ph->data->stop);
		if (ph->data->dead || !is_will_run (ph))
		{
			pthread_mutex_unlock (&ph->data->stop);
			break ;
		}
		pthread_mutex_unlock (&ph->data->stop);
		usleep (10);
	}
}

void	let_think(long sleep_time, t_philo *ph)
{
	long long	time;

	time = get_time ();
	while (sleep_time > 10)
		sleep_time /= 10;
	while (get_time() - time < sleep_time)
	{
		pthread_mutex_lock (&ph->data->stop);
		if (ph->data->dead || !is_will_run (ph))
		{
			pthread_mutex_unlock (&ph->data->stop);
			break ;
		}
		pthread_mutex_unlock (&ph->data->stop);
		usleep (5);
	}
}
