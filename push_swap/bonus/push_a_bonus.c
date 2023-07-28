/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:05:54 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/07 18:27:14 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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

int	*push_a_bn(int argc, char *argv[], t_info	*a_info, int size)
{
	int		*temp;
	int		*sort_temp;
	int		i;
	int		j;

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
		add_rear(temp[i++], a_info);
	free(temp);
	return (sort_temp);
}
