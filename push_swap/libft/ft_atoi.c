/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:31:01 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/07 16:52:56 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	exit_program(void)
{
	write(2, &"Error\n", 6);
	exit(1);
}

void	check_if_int(long long result)
{
	if (!(-2147483648 <= result && result <= 2147483647))
		exit_program();
}

void	ft_atoi(const char *str, int *temp, int *j)
{
	long long	result;
	int			countm;

	result = 0;
	countm = 1;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == 0)
			break ;
		if ((*str == '+' || *str == '-') && *(str++) == '-')
				countm = -countm;
		while (ft_isdigit(*str))
			result = result * 10 + (*str++ - '0');
		if (*str == 0 || *str++ == ' ')
		{
			check_if_int(countm * result);
			temp[(*j)++] = countm * result;
			countm = 1;
			result = 0;
		}
		else
			exit_program();
	}
}
