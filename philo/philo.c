/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:18:54 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/08/14 14:49:36 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo		*philos;
	t_info		info;
	t_status	*status;

	if (!(argc == 5 || argc == 6))
		return (print_error(INPUT_ERROR));
	if (check_arg(argc, argv))
		return (print_error(INPUT_ERROR));
	if (init_info_status(&info, &status, argv, argc))
		return (print_error(MALLOC_ERROR));
	if (init_philos(&philos, &info, status))
		return (print_error(MALLOC_ERROR));
	if (init_mutex(philos))
		return (print_error(MUTEX_ERROR));
	if (simulate(philos, &info))
		return (print_error(PTHREAD_CREATE_ERROR));
	detach(philos, info.p_num);
}
