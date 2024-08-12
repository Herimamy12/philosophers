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

typedef struct s_philo
{
	int				id;
	pthread_t		*thread;
	t_param			*param;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

}					t_philo;

typedef struct s_data
{
	t_param	*param;
	t_philo	*philo;
}			t_data;

//	DATA
void	print_param (t_param *param);
t_data	*new_data(int ac, char **av);
t_param	*new_param(int ac, char **av);
void	destroy_data(t_data *data);


#endif
