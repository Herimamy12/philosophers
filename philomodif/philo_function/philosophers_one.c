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

int	*new_fork_state(t_param *param)
{
	int		i;
	int		*fork;

	i = 0;
	fork = (int *)malloc(sizeof(int) * param->philo_nbr);
	if (!fork)
		return (NULL);
	while (i < param->philo_nbr)
	{
		fork[i] = 0;
		i++;
	}
	return (fork);
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
