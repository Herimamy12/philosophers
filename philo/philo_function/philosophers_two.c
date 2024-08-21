/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:39:46 by nherimam          #+#    #+#             */
/*   Updated: 2024/07/07 13:39:49 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_philo *ph)
{
	print_action ("has taken a fork", ph);
	let_sleep (ph->data->param->time_to_die, ph->data);
	print_action ("dead", ph);
}

void	is_eating(t_philo *ph)
{
	take_a_fork (ph);
	pthread_mutex_lock (&ph->data->stop);
	if (!is_will_run (ph))
	{
		drop_fork (ph);
		pthread_mutex_unlock (&ph->data->stop);
		return ;
	}
	print_action ("has taken a fork", ph);
	print_action ("has taken a fork", ph);
	print_action ("is eating", ph);
	ph->last_eat = get_time ();
	ph->nbr_eat++;
	pthread_mutex_unlock (&ph->data->stop);
	let_sleep (ph->data->param->time_to_eat, ph->data);
	drop_fork (ph);
}

void	*start_routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->data->param->philo_nbr == 1)
	{
		one_philo (ph);
		pthread_exit("succes");
	}
	if (ph->id % 2 != 0)
		is_thinking (ph);
	while (1)
	{
		pthread_mutex_lock (&ph->data->stop);
		if (!is_will_run (ph))
		{
			pthread_mutex_unlock (&ph->data->stop);
			break ;
		}
		pthread_mutex_unlock (&ph->data->stop);
		is_eating (ph);
		is_sleeping (ph);
		is_thinking (ph);
	}
	pthread_exit("succes");
}

void	run_routine(t_data *data)
{
	int		i;
	void	**char_val;

	i = 0;
	while (i < data->param->philo_nbr)
	{
		if (pthread_create (data->philo[i].thread, NULL,
				start_routine, &(data->philo[i])) != 0)
		{
			printf("Thread's create error\n");
			return ;
		}
		i++;
	}
	i = 0;
	while (i < data->param->philo_nbr)
	{
		char_val = NULL;
		if (pthread_join (*(data->philo[i].thread), char_val) != 0)
		{
			printf("Thread's join error\n");
			return ;
		}
		i++;
	}
}
