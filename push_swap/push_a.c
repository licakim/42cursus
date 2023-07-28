/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:48:10 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/07 18:25:50 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(int *temp, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (temp[i] == n)
			return (i);
		i++;
	}
	return (0);
}

void	quicksort(int left, int right, int *data)
{
	int	pivot;
	int	i;
	int	j;

	pivot = left;
	j = pivot;
	i = left + 1;
	if (left < right)
	{
		while (i <= right)
		{
			if (data[i] < data[pivot])
			{
				j++;
				swap(&data[j], &data[i]);
			}
			i++;
		}
		swap(&data[left], &data[j]);
		pivot = j;
		quicksort(left, pivot - 1, data);
		quicksort(pivot + 1, right, data);
	}
}

void	isvalid(int *temp, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (temp[i] == temp[j])
				exit_program();
			j++;
		}
		i++;
	}
}

int	*malloc_array(int size)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int) * size);
	if (!temp)
		exit_program();
	return (temp);
}

void	push_a(int argc, char *argv[], t_info	*a_info, int size)
{
	int		*temp;
	int		*sort_temp;
	int		i;
	int		j;
	int		num;

	temp = malloc_array(size);
	sort_temp = malloc_array(size);
	i = 1;
	while (i < argc)
		ft_atoi(argv[i++], temp, &j);
	isvalid(temp, j);
	check_if_sorted(temp, j);
	i = -1;
	while (++i < j)
		sort_temp[i] = temp[i];
	quicksort(0, j - 1, sort_temp);
	i = 0;
	while (i < j)
	{
		num = check(sort_temp, temp[i++], j);
		add_rear(num, a_info);
	}
	free(sort_temp);
	free(temp);
}
