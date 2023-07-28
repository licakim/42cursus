/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:09:27 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/07 20:13:29 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

int	free_all(t_deque *dq)
{
	t_deque	*temp;

	while (dq)
	{
		temp = dq;
		dq = (dq)-> next;
		free(temp);
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

void	init(t_deque **dq, t_info *info)
{
	t_deque	*head;

	head = malloc(sizeof(t_deque));
	if (!head)
		exit_program();
	head -> next = 0;
	*dq = head;
	info -> size = 1;
	info -> rear = *dq;
	info -> front = *dq;
}

void	check_if_empty(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		exit_program();
	while (str[i] == ' ')
		i++;
	if (str[i] == 0)
		exit_program();
}

void	check_if_sorted(int *temp, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (temp[i] > temp [i + 1])
			return ;
		i++;
	}
	ft_printf("OK\n");
	exit(0);
}
