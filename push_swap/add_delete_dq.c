/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_delete_dq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:02:22 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/07 14:47:14 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_min(t_info *info, int add)
{
	if (add < info ->min)
		info -> min = add;
}

void	add_front(int add, t_info *info)
{
	t_deque	*new;

	new = malloc(sizeof(t_deque));
	if (!new)
		exit_program();
	if (info -> size == 1)
	{
		info->list -> next = new;
		new -> next = 0;
		new -> prev = info->list;
		info -> rear = new;
		info->min = add;
	}
	else
	{
		info->list -> next = new;
		new -> next = info -> front;
		info -> front -> prev = new;
		new -> prev = info->list;
		check_min(info, add);
	}
	info -> front = new;
	new -> data = add;
	info -> size++;
}

void	delete_front(t_info *info)
{
	t_deque	*temp;

	if (info -> size == 1)
		return ;
	if (info -> size == 2)
	{
		temp = info -> front;
		info -> front = info->list;
		info -> rear = info->list;
		free(temp);
		info->list -> next = 0;
		info ->size--;
	}
	else
	{
		temp = info -> front;
		info -> front = info -> front -> next;
		free(temp);
		info->list -> next = info -> front;
		if (info -> front != 0)
			info-> front -> prev = info->list;
		info -> size--;
	}
}

void	add_rear(int add, t_info *info)
{
	t_deque	*new;

	new = malloc(sizeof(t_deque));
	if (!new)
		exit_program();
	if (info -> size == 1)
	{
		new -> next = 0;
		info->list-> next = new;
		new -> prev = info->list;
		new -> data = add;
		info -> front = new;
	}
	else
	{
		new -> data = add;
		info -> rear -> next = new;
		new -> prev = info -> rear;
		new -> next = 0;
	}
	info -> rear = new;
	info -> size++;
}

void	delete_rear(t_info *info)
{
	t_deque	*temp;

	if (info -> size == 1)
		return ;
	else
	{
		temp = info -> rear;
		info -> rear = info -> rear -> prev;
		if (info -> size == 2)
			info -> front = info -> front -> prev;
		free(temp);
		info -> rear -> next = 0;
		info -> size --;
	}
}
