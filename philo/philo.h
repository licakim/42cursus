/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:55:54 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/08/05 22:14:16 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INT_MAX 2147483647 

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
	PTHREAD_CREATE_ERROR,
};

enum	e_philo_status{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
};

typedef struct s_status{
	int				die_status;
	pthread_mutex_t	m_die_status;
	int				full_status;
	pthread_mutex_t	m_full_status;
}t_status;

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
	t_status		*status;
	t_info			*info;
	int				num;
	int				n_eat;
	pthread_t		t_id;
	time_t			last_meal_t;
	time_t			start_t;
	int				*r_fork;
	int				*l_fork;
	int				fork;
	pthread_mutex_t	*m_r_fork;
	pthread_mutex_t	*m_l_fork;
	pthread_mutex_t	m_fork;
	pthread_mutex_t	event;
}t_philo;

int		ft_atoi(const char *str);
int		check_arg(int argc, char *argv[]);
void	init_info_status(t_info *info, \
				t_status *status, char *argv[], int argc);
int		init_philos(t_philo **philos, t_info *info, t_status *status);
int		init_mutex(t_philo *philos, t_info *info, t_status *status);
void	print_philo_state(int state_n, t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_eat(t_philo *philo);
time_t	get_current_time(void);
void	*routine(void	*data);
int		print_error(int error_n);
int		check_die_status(t_philo *philos, t_info *info);
int		check_full_status(t_philo *philos, t_info *info);
void	monitoring(t_philo *philos, t_info *info);
int		simulate(t_philo *philos, t_info *info);
void	detach(t_philo *philos, int n);
void	philo_action(int action_time);


#endif
