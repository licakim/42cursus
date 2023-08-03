/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:46:48 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/08/03 19:47:09 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	init_info_status(t_info *info, t_status *status, char *argv[], int argc)
{
	info -> p_num = ft_atoi(argv[1]);
	info -> time_to_die = ft_atoi(argv[2]);
	info -> time_to_eat = ft_atoi(argv[3]);
	info -> time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info -> max_num = ft_atoi(argv[5]);
	else
		info -> max_num = -1;
	status -> die_status = 0;
	status -> full_status = 0;
}

int	init_philos(t_philo **philos, t_info *info, t_status *status)
{
	int	n;

	n = 0;
	*philos = malloc(sizeof(t_philo) * info->p_num);
	if (!philos)
		return (MALLOC_ERROR);
	while (n < info -> p_num)
	{
		(*philos)[n].status = status;
		(*philos)[n].info = info;
		(*philos)[n].num = n + 1;
		(*philos)[n].fork = 0;
		(*philos)[n].n_eat = 0;
		(*philos)[n].r_fork = &((*philos)[n].fork);
		(*philos)[n].l_fork = &((*philos)[(n + 1) % info -> p_num].fork);
		(*philos)[n].m_r_fork = &((*philos)[n].m_fork);
		(*philos)[n].m_l_fork = &((*philos)[(n + 1) % info -> p_num].m_fork);
		n++;
	}
	return (SUCCESS);
}

//뮤텍스 객체 파기 
int	init_mutex(t_philo *philos, t_info *info, t_status *status)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(status->m_die_status), NULL) == -1)
		return (MUTEX_ERROR);
	if (pthread_mutex_init(&(status->m_full_status), NULL) == -1)
		return (MUTEX_ERROR);
	while (i < info -> p_num)
	{
		if (pthread_mutex_init(&(philos[i].m_fork), NULL) == -1)
			return (MUTEX_ERROR);
		if (pthread_mutex_init(&(philos[i].event), NULL) == -1)
			return (MUTEX_ERROR);
		i++;
	}
	return (SUCCESS);
}