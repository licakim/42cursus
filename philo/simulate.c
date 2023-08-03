/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:49:03 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/08/03 20:10:28 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	philo_sleep(t_philo *philo)
{
	print_philo_state(SLEEP, philo);
	usleep(1000 * philo->info->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_philo_state(THINK, philo);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->m_r_fork);
	*(philo->r_fork) = 1;
	print_philo_state(FORK, philo);
	pthread_mutex_lock(philo->m_l_fork);
	*(philo->l_fork) = 1;
	print_philo_state(FORK, philo);
	pthread_mutex_lock(&(philo->event));
	philo -> last_meal_t = get_current_time();
	philo -> n_eat++;
	if (philo->n_eat == philo->info->max_num)
	{
		pthread_mutex_lock(&(philo->status->m_full_status));
		philo->status->full_status++;
		pthread_mutex_unlock(&(philo->status->m_full_status));
	}
	pthread_mutex_unlock(&(philo->event));
	print_philo_state(EAT, philo);
	usleep(1000 * philo->info->time_to_eat);
	*(philo->r_fork) = 0;
	pthread_mutex_unlock(philo->m_r_fork);
	*(philo->l_fork) = 0;
	pthread_mutex_unlock(philo->m_l_fork);
}

void	*routine(void	*data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo -> num % 2 == 0)
		usleep(1000);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (0);
}


int	simulate(t_philo *philos, t_info *info)
{
	int		n;
	time_t	c_time;

	n = 0;
	c_time = get_current_time();
	while (n < info -> p_num)
	{
		philos[n].start_t = c_time;
		philos[n].last_meal_t = c_time;
		if (pthread_create(&(philos[n].t_id), NULL, \
					routine, (void *)(&philos[n])))
		{
			detach(philos, n);
			return (PTHREAD_CREATE_ERROR);
		}
		n++;
	}
	monitoring(philos, info);
	return (0);
}