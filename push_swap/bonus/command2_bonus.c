/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:07:02 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/05 20:06:47 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

void	ra(t_info *a_info)
{
	int	temp;

	if (a_info -> size > 2)
	{
		temp = a_info -> front -> data;
		delete_front(a_info);
		add_rear(temp, a_info);
	}
}

void	rb(t_info *b_info)
{
	int	temp;

	if (b_info -> size > 2)
	{
		temp = b_info -> front -> data;
		delete_front(b_info);
		add_rear(temp, b_info);
	}
}

void	rr(t_info *a_info, t_info *b_info)
{
	int	temp;

	if (a_info -> size > 2 && b_info -> size > 2)
	{
		temp = a_info -> front -> data;
		delete_front(a_info);
		add_rear(temp, a_info);
		temp = b_info -> front -> data;
		delete_front(b_info);
		add_rear(temp, b_info);
	}
}
