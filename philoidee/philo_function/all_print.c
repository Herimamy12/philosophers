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

void	print_action(char *action, t_philo *ph)
{
	if (ph->data->dead)
		return ;
	printf("%lld %d %s\n", get_time () - ph->data->start_time, ph->id, action);
}

void	print_param(t_param *param)
{
	if (!param)
		return ;
	printf("=\t==\t==\t=\n");
	printf("nbr philo = %ld\n", param->philo_nbr);
	printf("time to die = %ld\n", param->time_to_die);
	printf("time to eat = %ld\n", param->time_to_eat);
	printf("time to sleep = %ld\n", param->time_to_sleep);
	printf("time to think = %ld\n", param->time_to_think);
	printf("nbr of time must eat = %ld\n", param->nbr_of_time_must_eat);
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
	printf("start time = %lld\n", data->start_time);
	print_param (data->param);
	print_philo (data->philo);
}
