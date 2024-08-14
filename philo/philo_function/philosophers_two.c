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

void	print_action(char *action, t_philo *ph)
{
	printf("%lld %d %s\n", get_time () - ph->data->start_time, ph->id, action);
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
			break ;
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
