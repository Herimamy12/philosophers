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

void	take_a_fork(t_philo *ph)
{
	printf("[Time] %d has taken a fork\n", ph->id);
	sleep (1);
}

void	is_eating(t_philo *ph)
{
	printf("[Time] %d is eating\n", ph->id);
	sleep (1);
}

void	is_sleeping(t_philo *ph)
{
	printf("[Time] %d is sleeping\n", ph->id);
	sleep (1);
}

void	is_thinking(t_philo *ph)
{
	printf("[Time] %d is thinking\n", ph->id);
	sleep (1);
}

int	is_dead(t_philo *ph)
{
	printf("[Time] %d dead\n", ph->id);
	sleep (1);
	return (1);
}

void	*start_routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		take_a_fork (ph);
		is_eating (ph);
		is_sleeping (ph);
		is_thinking (ph);
		if (is_dead (ph))
			break;
	}
	pthread_exit("succes");
}

void	run_routine(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->param->philo_nbr)
	{
		if (pthread_create (data->philo[i].thread, NULL, start_routine, &(data->philo[i])) != 0)
		{
			printf("Thread's create error\n");
			return ;
		}
		i++;
	}
	i = 0;
	while (i < data->param->philo_nbr)
	{
		void	**char_val;

		char_val = NULL;
		if (pthread_join (*(data->philo[i].thread), char_val) != 0)
		{
			printf("Thread's join error\n");
			return ;
		}
		i++;
	}
}
