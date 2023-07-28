/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:55:54 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/07/28 20:49:44 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<time.h>
# include<pthread.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include <sys/time.h>


enum	e_status{
	SUCCESS,
	FAIL,
	MALLOC_ERROR,
	INPUT_ERROR,
	MUTEX_ERROR,
};

enum	e_philo_status{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
};

typedef struct s_event{
	int				die_status;
	pthread_mutex_t	m_die_status;
}t_event;

typedef struct s_info
{
	int	p_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_num;
}t_info;

typedef struct s_philo
{
	t_info			*info;
	int				num;
	int				n_eat;
	pthread_t		t_id;
	long long		last_meal_t;
	long long		start_t;
	int				*r_fork;
	int				*l_fork;
	int				fork;
	pthread_mutex_t	*m_r_fork;
	pthread_mutex_t	*m_l_fork;
	pthread_mutex_t	m_fork;
	pthread_mutex_t	event;
}t_philo;

#endif
