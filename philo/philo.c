/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:18:54 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/07/28 21:47:39 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define INT_MAX 2147483647 

int	check_arg(int argc, char *argv[])
{
	int	n;
	int	i;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n <= 0 || n >= INT_MAX)
			return (INPUT_ERROR);
		i++;
	}
	return (SUCCESS);
}

int	init_info_philos(t_philo *philos, t_info *info, char *argv[], int argc)
{
	// info = malloc(sizeof(t_info));
	// if (!info)
	// 	return (MALLOC_ERROR);
	info -> p_num = ft_atoi(argv[1]);
	info -> time_to_die = ft_atoi(argv[2]);
	info -> time_to_eat = ft_atoi(argv[3]);
	info -> time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info -> max_num = ft_atoi(argv[5]);
	else
		info -> max_num = -1;
	return (init_philos(philos, info));
}

int	init_philos(t_philo *philos, t_info *info)
{
	int	n;

	n = 0;
	philos = malloc(sizeof(t_philo) * info->p_num);
	if (!philos)
		return (MALLOC_ERROR);
	while (n < info -> p_num)
	{
		philos[n].info = info;
		philos[n].num = n + 1;
		philos[n].fork = 0;
		philos[n].n_eat = 0;
		philos[n].r_fork = &(philos[n].fork);
		philos[n].l_fork = &(philos[(n + 1) % info -> p_num].fork);
		philos[n].m_r_fork = &(philos[n].m_fork);
		philos[n].l_fork = &(philos[(n + 1) % info -> p_num].m_fork);
		n++;
	}
	return (SUCCESS);
}

int	init_mutex(t_philo *philos, t_info *info, t_event *event)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(event->m_die_status), NULL) == -1)
		return (MUTEX_ERROR);
	event -> die_status = 0;
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


char	*print_philo_state(int state_n)
{
	//시간 추가
	const char	*state_m[5] = {
		"has taken a fork",
		"is eating",
		"is sleeping",
		"is thinking",
		"died",
	};
	return (state_m[state_n]);
}

void	philo_sleep(t_philo *philo)
{
	usleep(1000 * philo->info->time_to_sleep);
}

void	philo_think(t_philo *philo)
{

}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->m_fork));
	pthread_mutex_lock(&(philo->l_fork));
	usleep(1000 * philo->info->time_to_eat);
	//
	pthread_mutex_unlock(&(philo->m_fork));
	pthread_mutex_unlock(&(philo->l_fork));
	//값을 업데이트
}



void	routine(t_philo	*philo)
{
	if (philo -> num % 2 == 1)
		philo_eat(philo);
	else
		philo_think(philo);
}

int	create_philos(t_philo *philos, t_info *info)
{
	int	n;

	n = 0;
	while (n < info -> p_num)
	{
		//시간 저장
		pthread_create(&(philos[n].t_id), NULL, routine, &philos[n]);
		n++;
	}
}

int	print_error(int error_n)
{
	const char	*error_m[3] = {
		"malloc error",
		"argument error",
		"mutex error",
	};

	printf("%s", error_m[error_n - 2]);
	return (FAIL);
}

int main(int argc, char *argv[])
{
	t_philo	*philos;
	t_info	info;
	t_event	event;
	int		p_num;

	if (!(argc == 5 || argc == 6))
		return (print_error(INPUT_ERROR));
	if (check_arg(argc, argv))
		return (print_error(INPUT_ERROR));
	if (init_info_philos(philos, &info, philos, argc))
		return (print_error(MALLOC_ERROR));
	if (init_mutex(philos, &info, &event))
		return (print_error(MUTEX_ERROR));
}
