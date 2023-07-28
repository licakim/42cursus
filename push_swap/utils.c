/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:23:49 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/07 18:25:38 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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
	exit(0);
}
