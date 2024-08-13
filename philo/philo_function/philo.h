/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:17:13 by nherimam          #+#    #+#             */
/*   Updated: 2024/08/10 13:17:15 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../philosophers.h"

typedef struct s_param
{
	int	philo_nbr;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_of_time_must_eat;
}		t_param;

typedef struct s_fork
{
	pthread_mutex_t *fork;
}					t_fork;

typedef struct s_philo
{
	int				id;
	pthread_t		*thread;
	struct s_data	*data;
	t_fork			*l_fork;
	t_fork			*r_fork;
}					t_philo;

typedef struct s_data
{
	t_param	*param;
	t_philo	*philo;
	t_fork	*fork;
}			t_data;

//	PARAM
t_param	*new_param(int ac, char **av);
void	print_param(t_param *param);
void	destroy_param(t_param *param);

// DATA
t_data	*new_data(int ac, char **av);
void	print_data(t_data *data);
void	destroy_data(t_data *data);

// PHILO
t_philo	*new_philo(t_data *data);
void	print_philo(t_philo *philo);
void	destroy_philo(t_philo *philo);

// FORK
t_fork	*new_fork(t_param *param);
void	destroy_fork(t_fork *fork, int lim);

// ROUTINE
void	run_routine(t_data *data);

#endif
