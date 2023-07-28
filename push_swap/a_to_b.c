/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:50:17 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/06 21:21:57 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b_size(t_info *a_info, int *pivot, int *size)
{
	*size = a_info -> size - 1;
	pivot[0] = *size / 3 - 1;
	if (*size % 3 == 0)
		pivot[1] = pivot[0] + *size / 3;
	else
		pivot[1] = pivot[0] + *size / 3 + 1;
}

void	a_to_b_inner(t_info *a_info, t_info *b_info, int *pivot, int size)
{
	t_deque	*temp;
	t_deque	*temp2;

	temp = a_info->front;
	while (temp)
	{
		temp2 = temp-> next;
		if (temp->data <= pivot[0])
		{
			if (size <= 0)
				pb(a_info, b_info);
			else
				ra(a_info);
		}
		else if (pivot[0] < temp->data && temp->data <= pivot[1])
			pb(a_info, b_info);
		else
		{
			pb(a_info, b_info);
			rb(b_info);
		}
		temp = temp2;
		size--;
	}
}

void	a_to_b(t_info *a_info, t_info *b_info)
{
	int		pivot[2];
	int		size;

	a_to_b_size(a_info, pivot, &size);
	a_to_b_inner(a_info, b_info, pivot, size);
}
