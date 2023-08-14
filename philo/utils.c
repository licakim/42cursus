/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:50:29 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/08/14 14:54:33 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

time_t	get_current_time(void)
{
	struct timeval	tv;
	time_t			ct;

	gettimeofday(&tv, NULL);
	ct = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (ct);
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

int	check_arg(int argc, char *argv[])
{
	int	n;
	int	i;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n == -1)
			return (INPUT_ERROR);
		i++;
	}
	return (SUCCESS);
}

void	philo_action(int action_time)
{
	time_t	start_time;

	start_time = get_current_time();
	while (get_current_time() - start_time < action_time)
		usleep(200);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			countm;

	result = 0;
	countm = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			countm = -countm;
		str++;
	}
	while (*str)
	{
		if (!(*str >= 48 && *str <= 57))
			return (-1);
		result = result * 10 + (*str - '0');
		str++;
	}
	result *= countm;
	if (result <= 0 || result >= INT_MAX)
		return (-1);
	return (result);
}
