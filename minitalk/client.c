/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:00:08 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/06/12 17:47:45 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"client.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int num)
{
	if (num >= 48 && num <= 57)
		return (num);
	else
		return (0);
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
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (countm * result);
}

void	send_sig(pid_t pid, char *str, int i)
{
	int		bit_i;
	int		bit;

	bit_i = 0;
	while (bit_i < 8)
	{
		bit = str[i] >> (7 - bit_i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(60);
		bit_i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;
	int		i;
	int		len;

	if (argc != 3)
	{
		ft_printf("argument error\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		send_sig(pid, str, i);
		i++;
	}
}
