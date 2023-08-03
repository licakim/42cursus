/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:18:54 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/08/03 20:20:01 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

time_t	get_current_time(void)
{
	struct timeval	tv;
	time_t			ct;

	gettimeofday(&tv, NULL);
	ct = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (ct);
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

int	print_error(int error_n)
{
	const char	*error_m[3] = {
		"malloc error",
		"argument error",
		"mutex error",
	};

	printf("%s\n", error_m[error_n - 2]);
	return (FAIL);
}

int	check_die_status(t_philo *philos, t_info *info)
{
	int	n;
	int	starve_t;

	n = 0;
	while (n < info->p_num)
	{
		pthread_mutex_lock(&(philos[n].event));
		starve_t = get_current_time() - philos[n].last_meal_t;
		pthread_mutex_unlock(&(philos[n].event));
		if (starve_t >= info->time_to_die)
		{
			pthread_mutex_lock(&(philos->status->m_die_status));
			philos->status->die_status = 1;
			pthread_mutex_unlock(&(philos->status->m_die_status));
			print_philo_state(DIE, &philos[n]);
			return (1);
		}
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

void	detach(t_philo *philos, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_detach(philos[i].t_id);
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_philo		*philos;
	t_info		info;
	t_status	status;

	if (!(argc == 5 || argc == 6))
		return (print_error(INPUT_ERROR));
	if (check_arg(argc, argv))
		return (print_error(INPUT_ERROR));
	init_info_status(&info, &status, argv, argc);
	if (init_philos(&philos, &info, &status))
		return (print_error(MALLOC_ERROR));
	if (init_mutex(philos, &info, &status))
		return (print_error(MUTEX_ERROR));
	if(simulate(philos, &info))
		return (print_error(PTHREAD_CREATE_ERROR));
	detach(philos, info.p_num);
	//system("leaks philo");
}
