/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:06:44 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/05 19:30:01 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_info *a_info)
{
	int	temp1;

	if (a_info -> size <= 2)
		return ;
	temp1 = a_info -> front -> data;
	a_info -> front -> data = a_info -> front -> next -> data;
	a_info -> front -> next -> data = temp1;
}

void	sb(t_info *b_info)
{
	int	temp1;

	if (b_info -> size <= 2)
		return ;
	temp1 = b_info -> front -> data;
	b_info -> front -> data = b_info -> front -> next -> data;
	b_info -> front -> next -> data = temp1;
}

void	ss(t_info *a_info, t_info *b_info)
{
	sa(a_info);
	sb(b_info);
}
