/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:54:14 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/04 21:56:52 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	abs_sum(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	return (a + b);
}

t_deque	*find_min(t_info *b_info)
{
	t_deque	*temp;
	t_deque	*min;

	temp = b_info -> front;
	min = temp;
	while (temp)
	{
		if (abs_sum(temp->command[0], temp-> command[1]) < \
			abs_sum(min->command[0], min->command[1]))
			min = temp;
		temp = temp -> next;
	}
	return (min);
}

void	move_min_up(t_info *a_info, t_info *b_info, int *cmd)
{
	while (cmd[0] > 0 && cmd[1] > 0)
	{
		rr(a_info, b_info);
		cmd[0]--;
		cmd[1]--;
	}
	while (cmd[0] > 0)
	{
		ra(a_info);
		cmd[0]--;
	}
	while (cmd[1] > 0)
	{
		rb(b_info);
		cmd[1]--;
	}
}

void	move_min_down(t_info *a_info, t_info *b_info, int *cmd)
{
	while (cmd[0] < 0 && cmd[1] < 0)
	{
		rrr(a_info, b_info);
		cmd[0]++;
		cmd[1]++;
	}
	while (cmd[0] < 0)
	{
		rra(a_info);
		cmd[0]++;
	}
	while (cmd[1] < 0)
	{
		rrb(b_info);
		cmd[1]++;
	}
}

void	move_min(t_info *a_info, t_info *b_info)
{
	t_deque	*min;
	int		cmd[2];

	min = find_min(b_info);
	cmd[0] = min -> command[0];
	cmd[1] = min -> command[1];
	move_min_up(a_info, b_info, cmd);
	move_min_down(a_info, b_info, cmd);
	pa(a_info, b_info);
}
