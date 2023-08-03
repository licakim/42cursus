/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:55:18 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/08/03 20:12:00 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	print_error(int error_n)
{
	const char	*error_m[4] = {
		"malloc error",
		"argument error",
		"mutex error",
		"thread create error"
	};

	printf("%s\n", error_m[error_n - 2]);
	return (FAIL);
}

void	print_philo_state(int state_n, t_philo *philo)
{
	time_t		c_t;
	const char	*state_m[5] = {
		"has taken a fork",
		"is eating",
		"is sleeping",
		"is thinking",
		"died",
	};

	c_t = get_current_time() - philo->start_t;
	printf("%ld %d %s\n", c_t, philo->num, state_m[state_n]);
}