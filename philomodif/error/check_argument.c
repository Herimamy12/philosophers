/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:46:18 by nherimam          #+#    #+#             */
/*   Updated: 2024/07/22 12:46:20 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_argument.h"

int	number_param_err(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error : Number of parameter detected\n");
		printf("Try with 4 or 5 parameter\n");
		return (1);
	}
	return (0);
}

int	not_nbr_detected(char *str)
{
	int	index;

	index = 0;
	ft_shift_space (str, &index);
	if (str[index] == '+')
		index++;
	while (index < ft_strlen (str))
	{
		if (!ft_is_digit (str[index]))
		{
			printf("Error : Negative or not number detected\n");
			printf("Try with a positive value\n");
			return (1);
		}
		index++;
	}
	return (0);
}

int	param_not_nbr(int ac, char **av)
{
	int	index;

	index = 1;
	while (index < ac)
	{
		if (not_nbr_detected (av[index]))
			return (1);
		index++;
	}
	return (0);
}

int	check_arg(int ac, char **av)
{
	if (number_param_err (ac) || param_not_nbr (ac, av))
		return (1);
	return (0);
}
