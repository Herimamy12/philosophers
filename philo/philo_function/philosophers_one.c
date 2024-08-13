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

void	print_param(t_param *param)
{
	if (!param)
		return ;
	printf("=\t==\t==\t=\n");
	printf("nbr philo = %d\n", param->philo_nbr);
	printf("time to die = %d\n", param->time_to_die);
	printf("time to eat = %d\n", param->time_to_eat);
	printf("time to sleep = %d\n", param->time_to_sleep);
	printf("nbr of time must eat = %d\n", param->nbr_of_time_must_eat);
	printf("=\t==\t==\t=\n");
}

void	print_philo(t_philo *philo)
{
	int	i;

	i = 0;
	if (!philo)
		return ;
	printf("= == == == == =\n");
	while (i < philo->param->philo_nbr)
	{
		printf("philo id = %d\n", philo[i].id);
		i++;
	}
	printf("= == == == == =\n");
}

void	destroy_param(t_param *param)
{
	if (param)
		free (param);
}

void	destroy_philo(t_philo *philo)
{
	if (philo)
		free (philo);
}

void	destroy_data(t_data *data)
{
	if (!data)
		return ;
	if (data->param)
		destroy_param (data->param);
	if (data->philo)
		destroy_philo(data->philo);
	free (data);
}
