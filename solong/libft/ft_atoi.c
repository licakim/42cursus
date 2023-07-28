/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:31:01 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/02/08 15:46:36 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	long long	result;
	int			countm;

	result = 0;
	countm = 1;
	/*
		while ((9 <= *str && *str <= 13) || *str == 32)
			str++;
	*/
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
