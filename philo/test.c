/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:18:54 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/07/26 16:13:12 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/time.h>
#include"philo.h"
pthread_mutex_t mutex[5];


long long	current_time(void)
{
	struct timeval	t;
	long long		ms;

	gettimeofday(&t, NULL);
	ms = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (ms);
}

void	*exfunc(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	int t = 0;
	// while (t < 100)
	// {
	// 	if (info->number == info->number_of_philosophers)
	// 	{
	// 		pthread_mutex_lock(&mutex[0]);
	// 		pthread_mutex_lock(&mutex[info->number - 1]);
	// 		usleep(info->time_to_eat);
	// 		printf("%d eating\n",info->number);
	// 		pthread_mutex_unlock(&mutex[0]);
	// 		pthread_mutex_unlock(&mutex[info->number - 1]);
	// 		printf("%d sleeping\n",info->number);
	// 		usleep(info->time_to_sleep);
	// 	}
	// 	else {
	// 		pthread_mutex_lock(&mutex[info->number - 1]);
	// 		pthread_mutex_lock(&mutex[info->number]);
	// 		usleep(info->time_to_eat);
	// 		printf("%d eating\n",info->number);
	// 		pthread_mutex_unlock(&mutex[info->number - 1]);
	// 		pthread_mutex_unlock(&mutex[info->number]);
	// 		printf("%d sleeping\n",info->number);
	// 		usleep(info->time_to_sleep);
	// 	}
	// 	t++;
	// }
}

void	init_info(char *argv[], t_info *info)
{
	info -> number_of_philosophers = atoi(argv[1]);
	info -> time_to_die = atoi(argv[2]);
	info -> time_to_sleep = atoi(argv[3]);
}

void	check_time()
{

}

int	main(int argc, char *argv[])
{
	pthread_t	*id;
	int			p_n;
	t_info		*info;
	int			i;

	p_n = 0;
	int nP=atoi(argv[1]);
	info = (t_info *)malloc(sizeof(t_info) * nP);
	while (p_n < nP){
		init_info(argv, &info[p_n]);
		p_n++;
	}
	i = 0;
	while (i < nP)
		pthread_mutex_init(&mutex[i++], NULL);
	id = (pthread_t *)malloc(sizeof(pthread_t) * nP);
	p_n = 0;
	while (p_n < nP)
	{
		info[p_n].number = p_n + 1;
		if (pthread_create(&id[p_n], NULL, exfunc, &info[p_n]) != 0)
			exit(1);
		p_n++;
	}
	p_n = 0;
	while (p_n < nP)
	{
		pthread_join(id[p_n], 0);
		p_n++;
	}
	while (i < nP)
		pthread_mutex_destroy(&mutex[i++]);
	return (0);
}
