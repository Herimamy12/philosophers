/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:39:34 by nherimam          #+#    #+#             */
/*   Updated: 2024/07/07 13:39:35 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday (&time, NULL) == -1)
		printf("gettimeofday() error\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	destroy_param(t_param *param)
{
	if (param)
		free (param);
}

void	destroy_philo(t_philo *philo)
{
	int	i;
	int	lim;

	i = 0;
	if (!philo)
		return ;
	lim = philo->data->param->philo_nbr;
	while (i < lim)
	{
		free (philo[i].thread);
		i++;
	}
	free (philo);
}

void	destroy_fork(t_fork *fork, int lim)
{
	int	i;

	if (!fork)
		return ;
	i = 0;
	while (i < lim)
	{
		free (fork[i].fork);
		i++;
	}
	free (fork);
}

void	destroy_data(t_data *data)
{
	if (!data)
		return ;
	if (data->fork)
		destroy_fork (data->fork, data->param->philo_nbr);
	if (data->philo)
		destroy_philo(data->philo);
	if (data->param)
		destroy_param (data->param);
	free (data);
}
