/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:32:24 by nherimam          #+#    #+#             */
/*   Updated: 2024/07/22 12:32:27 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (check_arg(ac, av))
		return (1);
	data = new_data (ac, av);
	if (!data)
	{
		printf("Error data init\n");
		destroy_data (data);
		return (1);
	}
	// print_param (data->param);
	run_routine (data);
	destroy_data (data);
	return (0);
}
