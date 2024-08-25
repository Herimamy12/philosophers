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
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	time_to_think;
	long	nbr_of_time_must_eat;
}		t_param;

typedef struct s_fork
{
	pthread_mutex_t	*fork;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				nbr_eat;
	int				l_state;
	int				r_state;
	pthread_t		*thread;
	struct s_data	*data;
	t_fork			l_fork;
	t_fork			r_fork;
	long long		last_eat;
}					t_philo;

typedef struct s_data
{
	int				dead;
	int				*fork_state;
	long long		start_time;
	t_fork			*fork;
	t_param			*param;
	t_philo			*philo;
	pthread_mutex_t	stop;
}					t_data;

// TIME
long long	get_time(void);

//	PARAM
t_param		*new_param(int ac, char **av);
void		print_param(t_param *param);
void		destroy_param(t_param *param);
int			false_param(t_param *param);

// DATA
t_data		*new_data(int ac, char **av);
void		print_data(t_data *data);
void		destroy_data(t_data *data);

// PHILO
t_philo		*new_philo(t_data *data);
void		print_philo(t_philo *philo);
void		destroy_philo(t_philo *philo);
void		one_philo(t_philo *ph);

// FORK
t_fork		*new_fork(t_param *param);
int			*new_fork_state(t_param *param);
void		destroy_fork(t_fork *fork, int lim);
void		take_a_fork(t_philo *ph);
void		drop_fork(t_philo *ph);

// ROUTINE
void		run_routine(t_data *data);
void		*start_routine(void *philo);
// 
void		is_eating(t_philo *ph);
void		is_sleeping(t_philo *ph);
void		is_thinking(t_philo *ph);
void		print_action(char *action, t_philo *ph);

// CONDITION
int			is_full(t_philo *ph);
int			is_dead(t_philo *ph);
int			is_will_run(t_philo *ph);

// SLEEP
void		let_sleep(long sleep_time, t_philo *ph);
void		let_think(long sleep_time, t_philo *ph);

#endif
