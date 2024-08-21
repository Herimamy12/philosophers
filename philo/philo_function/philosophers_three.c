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
	if (pthread_mutex_lock (ph->r_fork.fork) != 0)
		printf("right fork lock error\n");
	if (pthread_mutex_lock (ph->l_fork.fork) != 0)
		printf("left fork lock error\n");
	print_action ("has taken a fork", ph);
	print_action ("has taken a fork", ph);
}

void	drop_fork(t_philo *ph)
{
	if (pthread_mutex_unlock (ph->r_fork.fork) != 0)
		printf("drop left fork error\n");
	if (pthread_mutex_unlock (ph->l_fork.fork) != 0)
		printf("drop right fork error\n");
}

void	is_eating(t_philo *ph)
{
	take_a_fork (ph);
	if (!is_will_run (ph))
	{
		drop_fork (ph);
		return ;
	}
	print_action ("is eating", ph);
	pthread_mutex_lock (&ph->data->stop);
	ph->last_eat = get_time ();
	ph->nbr_eat++;
	pthread_mutex_unlock (&ph->data->stop);
	let_sleep (ph->data->param->time_to_eat, ph->data);
	drop_fork (ph);
}

void	is_sleeping(t_philo *ph)
{
	if (!is_will_run (ph))
		return ;
	print_action ("is sleeping", ph);
	let_sleep (ph->data->param->time_to_sleep, ph->data);
}

void	is_thinking(t_philo *ph)
{
	if (!is_will_run (ph))
		return ;
	print_action ("is thinking", ph);
	usleep (ph->data->param->time_to_think);
	// let_sleep (ph->data->param->time_to_think, ph->data);
}

int	is_dead(t_philo *ph)
{
	if ((get_time () - ph->last_eat) >= (ph->data->param->time_to_die))
	{
		print_action ("dead", ph);
		return (1);
	}
	return (0);
}
