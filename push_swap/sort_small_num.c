/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:43:56 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/07 15:58:49 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_num(t_info *a_info, int min)
{
	if (a_info -> front -> data == min)
		ra(a_info);
	else if (a_info -> rear -> data != min)
		rra(a_info);
	if (a_info->front->data != min + 1)
		sa(a_info);
	rra(a_info);
}

void	sort_four_num(t_info *a_info, t_info *b_info)
{
	min_to_top(a_info, 0);
	pb(a_info, b_info);
	sort_three_num(a_info, 1);
	pa(a_info, b_info);
}

void	sort_five_num(t_info *a_info, t_info *b_info)
{
	min_to_top(a_info, 0);
	pb(a_info, b_info);
	min_to_top(a_info, 1);
	pb(a_info, b_info);
	sort_three_num(a_info, 2);
	pa(a_info, b_info);
	pa(a_info, b_info);
}

void	sort_two_num(t_info *a_info)
{
	if (a_info->front->data != 0)
		sa(a_info);
}

void	sort_small_num(t_info *a_info, t_info *b_info, int size)
{
	if (2 <= size && size <= 5)
	{
		if (size == 2)
			sort_two_num(a_info);
		if (size == 3)
			sort_three_num(a_info, 0);
		if (size == 4)
			sort_four_num(a_info, b_info);
		if (size == 5)
			sort_five_num(a_info, b_info);
		free_all(a_info->list);
		free(b_info->list);
		exit(0);
	}
}
