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

// void	take_a_fork(t_philo *ph)
// {
// 	if (ph->l_fork.fork < ph->r_fork.fork)
// 	{
// 		if (pthread_mutex_lock (ph->l_fork.fork) != 0)
// 			printf("left fork lock error\n");
// 		if (pthread_mutex_lock (ph->r_fork.fork) != 0)
// 			printf("right fork lock error\n");
// 	}
// 	else
// 	{
// 		if (pthread_mutex_lock (ph->r_fork.fork) != 0)
// 			printf("right fork lock error\n");
// 		if (pthread_mutex_lock (ph->l_fork.fork) != 0)
// 			printf("left fork lock error\n");
// 	}
// }

// void	drop_fork(t_philo *ph)
// {
// 	if (ph->l_fork.fork < ph->r_fork.fork)
// 	{
// 		if (pthread_mutex_unlock (ph->l_fork.fork) != 0)
// 			printf("drop right fork error\n");
// 		if (pthread_mutex_unlock (ph->r_fork.fork) != 0)
// 			printf("drop left fork error\n");
// 	}
// 	else
// 	{
// 		if (pthread_mutex_unlock (ph->r_fork.fork) != 0)
// 			printf("drop right fork error\n");
// 		if (pthread_mutex_unlock (ph->l_fork.fork) != 0)
// 			printf("drop left fork error\n");
// 	}
// }

// void	take_a_fork(t_philo *ph)
// {
// 	pthread_mutex_lock (&ph->data->stop);
// 	while (is_will_run (ph))
// 	{
// 		if (ph->l_fork.fork < ph->r_fork.fork)
// 		{
// 			pthread_mutex_lock (ph->l_fork.fork);
// 			pthread_mutex_lock (ph->r_fork.fork);
// 		}
// 		else
// 		{
// 			pthread_mutex_lock (ph->r_fork.fork);
// 			pthread_mutex_lock (ph->l_fork.fork);
// 		}
// 		if (!ph->l_fork.value)
// 			ph->l_fork.value = 1;
// 		if (!ph->r_fork.value)
// 			ph->r_fork.value = 1;
// 		if (ph->r_fork.value && ph->l_fork.value)
// 		{
// 			pthread_mutex_unlock (ph->l_fork.fork);
// 			pthread_mutex_unlock (ph->r_fork.fork);
// 			break ;
// 		}
// 		else
// 		{
// 			ph->l_fork.value = 0;
// 			ph->r_fork.value = 0;
// 			pthread_mutex_unlock (ph->l_fork.fork);
// 			pthread_mutex_unlock (ph->r_fork.fork);
// 		}
// 	}
// 	pthread_mutex_unlock (&ph->data->stop);
// }

void	take_a_fork(t_philo *ph)
{
	pthread_mutex_lock (&ph->data->stop);
	if (!is_will_run (ph))
	{
		pthread_mutex_unlock (&ph->data->stop);
		return ;
	}
	if (!ph->l_fork)
	{
		ph->l_fork = 1;
		ph->fork_count++;
	}
	if (!ph->r_fork)
	{
		ph->r_fork = 1;
		ph->fork_count++;
	}
	if (ph->fork_count < 2)
	{
		if (ph->l_fork)
			ph->l_fork = 0;
		if (ph->r_fork)
			ph->r_fork = 0;
		ph->fork_count = 0;
		pthread_mutex_unlock (&ph->data->stop);	
		take_a_fork (ph);
	}
	pthread_mutex_unlock (&ph->data->stop);
}

void	drop_fork(t_philo *ph)
{
	pthread_mutex_lock (&ph->data->stop);
	ph->l_fork = 0;
	ph->r_fork = 0;
	ph->fork_count = 0;
	pthread_mutex_unlock (&ph->data->stop);
}

/* ########################################################## */

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
	let_sleep (ph->data->param->time_to_sleep, ph);
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
	let_think (ph->data->param->time_to_think, ph);
}

int	is_dead(t_philo *ph)
{
	long long	time;

	time = get_time ();
	if (ph->data->dead)
		return (1);
	if ((time - ph->last_eat) > (long long)(ph->data->param->time_to_die))
	{
		print_action ("dead", ph);
		ph->data->dead = 1;
		return (1);
	}
	return (0);
}
