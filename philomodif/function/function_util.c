/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:24:25 by nherimam          #+#    #+#             */
/*   Updated: 2024/07/22 13:24:26 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_util.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_is_space(char set)
{
	return ((9 <= set && set <= 13) || set == 32);
}

void	ft_shift_space(char *str, int *index)
{
	while (str[*index] && ft_is_space (str[*index]))
		*index = *index + 1;
}

int	ft_is_digit(char set)
{
	return ('0' <= set && set <= '9');
}

long	ft_atoi(char *str)
{
	long	res;
	int		sign;
	int		index;

	res = 0;
	sign = 1;
	index = 0;
	ft_shift_space (str, &index);
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index++] == '-')
			sign = -1;
	}
	while (str[index] && ft_is_digit (str[index]))
	{
		res *= 10;
		res += (str[index] - '0');
		index++;
	}
	res *= sign;
	return (res);
}
