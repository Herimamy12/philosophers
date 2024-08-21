/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:24:32 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/14 13:24:33 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_a_fork(t_philo *ph)
{
	if (ph->l_fork.fork < ph->r_fork.fork)
	{
		if (pthread_mutex_lock (ph->l_fork.fork) != 0)
			printf("left fork lock error\n");
		if (pthread_mutex_lock (ph->r_fork.fork) != 0)
			printf("right fork lock error\n");
	}
	else
	{
		if (pthread_mutex_lock (ph->r_fork.fork) != 0)
			printf("right fork lock error\n");
		if (pthread_mutex_lock (ph->l_fork.fork) != 0)
			printf("left fork lock error\n");
	}
}

void	drop_fork(t_philo *ph)
{
	if (ph->l_fork.fork < ph->r_fork.fork)
	{
		if (pthread_mutex_unlock (ph->l_fork.fork) != 0)
			printf("drop right fork error\n");
		if (pthread_mutex_unlock (ph->r_fork.fork) != 0)
			printf("drop left fork error\n");
	}
	else
	{
		if (pthread_mutex_unlock (ph->r_fork.fork) != 0)
			printf("drop right fork error\n");
		if (pthread_mutex_unlock (ph->l_fork.fork) != 0)
			printf("drop left fork error\n");
	}
}

void	is_sleeping(t_philo *ph)
{
	pthread_mutex_lock (&ph->data->stop);
	if (!is_will_run (ph))
	{
		pthread_mutex_unlock (&ph->data->stop);
		return ;
	}
	print_action ("is sleeping", ph);
	pthread_mutex_unlock (&ph->data->stop);
	let_sleep (ph->data->param->time_to_sleep, ph->data);
}

void	is_thinking(t_philo *ph)
{
	pthread_mutex_lock (&ph->data->stop);
	if (!is_will_run (ph))
	{
		pthread_mutex_unlock (&ph->data->stop);
		return ;
	}
	print_action ("is thinking", ph);
	pthread_mutex_unlock (&ph->data->stop);
	let_think (ph->data->param->time_to_think, ph->data);
}

int	is_dead(t_philo *ph)
{
	if (ph->data->dead)
		return (1);
	if ((get_time () - ph->last_eat) >= (ph->data->param->time_to_die))
	{
		print_action ("dead", ph);
		ph->data->dead = 1;
		return (1);
	}
	return (0);
}
