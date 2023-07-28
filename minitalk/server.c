/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:49:14 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/06/12 17:36:06 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"server.h"

t_char	g_c;

void	handler(int sig)
{
	g_c.c <<= 1;
	if (sig == SIGUSR1)
		g_c.c += 1;
	++g_c.bit_idx;
	if (g_c.bit_idx == 8)
	{
		write(1, &g_c.c, 1);
		g_c.bit_idx = 0;
		g_c.c = 0;
	}
}

int	main(void)
{
	ft_printf("server pid: %d\n", getpid());
	g_c.c = 0;
	g_c.bit_idx = 0;
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
