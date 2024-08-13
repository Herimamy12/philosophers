/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_zero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:39:23 by nherimam          #+#    #+#             */
/*   Updated: 2024/07/07 13:39:25 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	false_param(t_param *param)
{
	int	ret;

	ret = 0;
	if (!param->philo_nbr || !param->time_to_die || !param->time_to_eat)
		ret = 1;
	if (!param->time_to_sleep || !param->nbr_of_time_must_eat)
		ret = 1;
	if (ret)
		printf("Parameter 00 detected\n");
	return (ret);
}

t_param	*new_param(int ac, char **av)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->philo_nbr = ft_atoi (av[1]);
	param->time_to_die = ft_atoi (av[2]);
	param->time_to_eat = ft_atoi (av[3]);
	param->time_to_sleep = ft_atoi (av[4]);
	param->nbr_of_time_must_eat = -1;
	if (ac == 6)
		param->nbr_of_time_must_eat = ft_atoi (av[5]);
	if (false_param (param))
	{
		destroy_param (param);
		return (NULL);
	}
	return (param);
}

t_philo	*new_philo(t_param *param)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * param->philo_nbr);
	if (!philo)
		return (NULL);
	while (i < param->philo_nbr)
	{
		philo[i].id = i + 1;
		philo[i].param = param;
		philo[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
		i++;
	}
	return (philo);
}

t_data	*new_data(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	t_param	*param;

	param = new_param (ac, av);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	if (!param)
	{
		free (data);
		return (NULL);
	}
	philo = new_philo (param);
	data->param = param;
	data->philo = philo;
	return (data);
}

void	print_data(t_data *data)
{
	if (!data)
		return ;
	print_param (data->param);
	print_philo (data->philo);
}
