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
	if (!param->time_to_die || !param->time_to_eat)
		ret = 1;
	if (!param->time_to_sleep || !param->nbr_of_time_must_eat)
		ret = 1;
	if (!param->philo_nbr)
		ret = 1;
	if (ret)
		printf("Value of one or more parameter 0\n");
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
	param->time_to_think = ft_atoi (av[2]) - ft_atoi (av[3])
		- ft_atoi (av[4]);
	if (param->time_to_think < 0)
		param->time_to_think = 0;
	return (param);
}

t_philo	*new_philo(t_data *data)
{
	int		i;
	int		lim;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * data->param->philo_nbr);
	if (!philo)
		return (NULL);
	lim = data->param->philo_nbr;
	while (i < lim)
	{
		philo[i].id = i + 1;
		philo[i].nbr_eat = 0;
		philo[i].data = data;
		philo[i].last_eat = data->start_time;
		philo[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
		philo[i].l_fork.fork = data->fork[i].fork;
		if (i < lim - 1)
			philo[i].r_fork.fork = data->fork[i + 1].fork;
		else
			philo[i].r_fork.fork = data->fork[0].fork;
		i++;
	}
	return (philo);
}

t_fork	*new_fork(t_param *param)
{
	int		i;
	t_fork	*fork;

	i = 0;
	fork = (t_fork *)malloc(sizeof(t_fork) * param->philo_nbr);
	if (!fork)
		return (NULL);
	while (i < param->philo_nbr)
	{
		fork[i].fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!fork[i].fork)
		{
			printf("Error fork alloc\n");
			destroy_fork (fork, param->philo_nbr);
			return (NULL);
		}
		if (pthread_mutex_init (fork[i].fork, NULL))
		{
			printf("Error fork init\n");
			destroy_fork (fork, param->philo_nbr);
			return (NULL);
		}
		i++;
	}
	return (fork);
}

t_data	*new_data(int ac, char **av)
{
	t_data	*data;
	t_fork	*fork;
	t_philo	*philo;
	t_param	*param;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->dead = 0;
	data->start_time = get_time ();
	param = new_param (ac, av);
	if (!param)
	{
		free (data);
		return (NULL);
	}
	data->param = param;
	fork = new_fork (param);
	data->fork = fork;
	philo = new_philo (data);
	data->philo = philo;
	pthread_mutex_init (&data->stop, NULL);
	return (data);
}
