/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:59:17 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/02/06 18:51:04 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	end_game(void)
{
	ft_printf("게임을 종료합니다\n");
	exit(0);
}

int	success_game(void)
{
	ft_printf("축하합니다!!게임을 통과하셨습니다\n");
	exit(0);
}

void	error_msg(char *str)
{
	ft_printf("Error\n");
	ft_printf(str);
	exit(1);
}

int	ft_len(const char *s)
{	
	int	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*join_line(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	if (!temp)
		error_msg("");
	return (temp);
}
