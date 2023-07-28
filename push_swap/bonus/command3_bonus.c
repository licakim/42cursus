/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:06:24 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/05 19:30:15 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_info *a_info, t_info *b_info)
{
	int	temp;

	if (b_info -> size <= 1)
		return ;
	temp = b_info -> front -> data;
	delete_front(b_info);
	add_front(temp, a_info);
}

void	pb(t_info *a_info, t_info *b_info)
{
	int	temp;

	if (a_info -> size <= 1)
		return ;
	temp = a_info -> front -> data;
	delete_front(a_info);
	add_front(temp, b_info);
}

void	rra(t_info *a_info)
{
	int	temp;

	if (a_info -> size > 2)
	{
		temp = a_info -> rear -> data;
		delete_rear(a_info);
		add_front(temp, a_info);
	}
}

void	rrb(t_info *b_info)
{
	int	temp;

	if (b_info -> size > 2)
	{
		temp = b_info -> rear -> data;
		delete_rear(b_info);
		add_front(temp, b_info);
	}
}

void	rrr(t_info *a_info, t_info *b_info)
{
	int	temp;

	if (a_info -> size > 2 && b_info -> size > 2)
	{
		temp = a_info -> rear -> data;
		delete_rear(a_info);
		add_front(temp, a_info);
		temp = b_info -> rear -> data;
		delete_rear(b_info);
		add_front(temp, b_info);
	}
}
