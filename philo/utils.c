/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:50:29 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/08/03 19:55:13 by hyunjki2         ###   ########.fr       */
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
		if (n <= 0 || n >= INT_MAX)
			return (INPUT_ERROR);
		i++;
	}
	return (SUCCESS);
}
