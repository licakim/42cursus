/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:51:45 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/08/14 19:15:08 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	check_die_status(t_philo *philos, t_info *info)
{
	int	n;
	int	starve_t;

	n = 0;
	while (n < info->p_num)
	{
		pthread_mutex_lock(&(philos[n].event));
		starve_t = get_current_time() - philos[n].last_meal_t;
		if (starve_t >= info->time_to_die)
		{
			pthread_mutex_lock(&(philos->status->m_die_status));
			philos->status->die_status = 1;
			printf("%ld %d died", \
					get_current_time() - philos[n].start_t, philos[n].num);
			return (1);
		}
		pthread_mutex_unlock(&(philos[n].event));
		n++;
	}
	return (0);
}

int	check_full_status(t_philo *philos, t_info *info)
{
	int	full_philo;

	pthread_mutex_lock(&(philos->status->m_full_status));
	full_philo = philos->status->full_status;
	pthread_mutex_unlock(&(philos->status->m_full_status));
	if (full_philo == info->p_num)
		return (1);
	return (0);
}

void	monitoring(t_philo *philos, t_info *info)
{
	while (1)
	{
		if (check_die_status(philos, info))
			break ;
		if (info -> max_num != -1)
			if (check_full_status(philos, info))
				break ;
		usleep(1000);
	}
}
