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
	{
		printf("false parameter detected\n");
		ret = 1;
	}
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
		free (param);
		return (NULL);
	}
	return (param);
}

t_data	*new_data(int ac, char **av)
{
	t_data	*data;
	t_param	*param;

	param = new_param (ac, av);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	if (!param /*|| !philo*/)
	{
		free (data);
		return (NULL);
	}
	data->param = param;
	return (data);
}

void	print_param (t_param *param)
{
	printf("=\t==\t==\t==\t==\t=\n");
	printf("nbr philo = %d\n", param->philo_nbr);
	printf("time to die = %d\n", param->time_to_die);
	printf("time to eat = %d\n", param->time_to_eat);
	printf("time to sleep = %d\n", param->time_to_sleep);
	printf("nbr of time must eat = %d\n", param->nbr_of_time_must_eat);
	printf("=\t==\t==\t==\t==\t=\n");
}

void	destroy_data(t_data *data)
{
	free (data->param);
	free (data);
}
