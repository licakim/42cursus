/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:59:47 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/04 21:59:47 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	min_to_top(t_info *info, int min)
{
	t_deque	*temp;
	int		cnt;

	temp = info-> front;
	cnt = 0;
	while (temp -> data != min)
	{
		temp = temp -> next;
		cnt++;
	}
	if (cnt > (info->size -1) / 2)
		cnt = cnt - info -> size + 1;
	while (cnt < 0)
	{
		rra(info);
		cnt++;
	}
	while (cnt > 0)
	{
		ra(info);
		cnt--;
	}
}

void	b_to_a(t_info *a_info, t_info *b_info)
{
	t_deque	*cnt;
	int		n;

	if (b_info->size == 1)
	{
		min_to_top(a_info, 0);
		free(b_info -> front);
		return ;
	}
	cnt = b_info -> front;
	n = 0;
	while (cnt)
	{
		check_a_count(cnt, a_info);
		check_count(cnt, b_info, n, 1);
		cnt = cnt ->next;
		n++;
	}
	move_min(a_info, b_info);
	b_to_a(a_info, b_info);
}
