/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:52:34 by nherimam          #+#    #+#             */
/*   Updated: 2024/07/22 13:52:35 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_UTIL_H
# define FUNCTION_UTIL_H

# include "../philosophers.h"

int		ft_strlen(char *str);
int		ft_is_space(char set);
void	ft_shift_space(char *str, int *index);
int		ft_is_digit(char set);
long	ft_atoi(char *str);

#endif
