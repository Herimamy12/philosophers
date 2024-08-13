/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:17:58 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/13 16:18:00 by nherimam         ###   ########.fr       */
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
	while (i < philo->data->param->philo_nbr)
	{
		printf("philo id = %d\n", philo[i].id);
		i++;
	}
	printf("= == == == == =\n");
}

void	print_data(t_data *data)
{
	if (!data)
		return ;
	print_param (data->param);
	print_philo (data->philo);
}