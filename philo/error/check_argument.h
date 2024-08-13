/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:32:22 by nherimam          #+#    #+#             */
/*   Updated: 2024/07/22 14:32:26 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARGUMENT_H
# define CHECK_ARGUMENT_H

# include "../philosophers.h"

int	number_param_err(int ac);
int	not_nbr_detected(char *str);
int	param_not_nbr(int ac, char **av);
int	check_arg(int ac, char **av);

#endif
