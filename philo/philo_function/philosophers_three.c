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
	if (pthread_mutex_lock (ph->l_fork.fork) != 0)
		printf("left fork lock error\n");
	if (pthread_mutex_lock (ph->r_fork.fork) != 0)
		printf("right fork lock error\n");
	print_action ("has taken a fork", ph);
	print_action ("has taken a fork", ph);
}

void	is_eating(t_philo *ph)
{
	print_action ("is eating", ph);
	usleep (ph->data->param->time_to_eat * 1000);
	if (pthread_mutex_unlock (ph->l_fork.fork) != 0)
		printf("left fork unlock error\n");
	if (pthread_mutex_unlock (ph->r_fork.fork) != 0)
		printf("right fork unlock error\n");
	ph->last_eat = get_time () - ph->data->start_time;
}

void	is_sleeping(t_philo *ph)
{
	print_action ("is sleeping", ph);
	usleep (ph->data->param->time_to_sleep * 1000);
}

void	is_thinking(t_philo *ph)
{
	print_action ("is thinking", ph);
}

int	is_dead(t_philo *ph)
{
	static int	count = 0;

	count++;
	if ((get_time () - ph->last_eat) >= (ph->data->param->time_to_die))
	{
		print_action ("dead", ph);
		return (1);
	}
	return (0);
}
