/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:57:59 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/04 22:42:21 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	check_count(t_deque *cnt, t_info *dq_info, int n, int i)
{
	int	size;

	if (dq_info -> size <= 2)
		cnt -> command[i] = 0;
	size = dq_info ->size -1;
	if (n > size / 2)
		n = n - size;
	cnt ->command[i] = n;
}

int	get_count_to_min(t_info *a_info)
{
	int		count;
	t_deque	*temp;

	count = 0;
	temp = a_info->front;
	while (temp->data != a_info->min && temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

int	check_a_count_inner(t_deque *b, t_info *a_info, int *size)
{
	t_deque	*temp;
	int		count;

	count = 0;
	temp = a_info -> front;
	while (*size > 1)
	{
		count++;
		if (temp -> data < b -> data && temp -> next -> data > b -> data)
			break ;
		temp = temp -> next;
		*size = *size -1;
	}
	return (count);
}

void	check_a_count(t_deque *b, t_info *a_info)
{
	int		count;
	int		size;

	if (a_info -> size <= 2)
	{
		b -> command[0] = 0;
		return ;
	}
	size = a_info -> size -1;
	if (size > 1)
		count = check_a_count_inner(b, a_info, &size);
	if (size == 1 && a_info -> rear -> data < b->data \
		&& a_info->front->data > b->data)
	{
		b -> command[0] = 0;
		return ;
	}
	if (size == 1)
		count = get_count_to_min(a_info);
	check_count(b, a_info, count, 0);
}
