/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:04:48 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/09 15:05:45 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	init(t_deque **dq, t_info *info)
{
	t_deque	*head;

	head = malloc(sizeof(t_deque));
	if (!head)
		exit_program();
	head -> next = 0;
	*dq = head;
	info -> size = 1;
	info -> rear = *dq;
	info -> front = *dq;
}

void	check_if_empty(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		exit_program();
	while (str[i] == ' ')
		i++;
	if (str[i] == 0)
		exit_program();
}

void	count_num(int argc, char *argv[], int *size, int i)
{
	int	k;

	while (++i < argc)
	{
		check_if_empty(argv[i]);
		k = 0;
		while (argv[i][k])
		{
			while (argv[i][k] == ' ')
				k++;
			if (argv[i][k] == 0)
				break ;
			if (argv[i][k] == '+' || argv[i][k] == '-')
				k++;
			while (ft_isdigit(argv[i][k]))
				k++;
			if (argv[i][k] == 0 || argv[i][k++] == ' ')
				*size = *size + 1;
			else
				exit_program();
		}
	}
}

int	free_all(t_deque *dq)
{
	t_deque	*temp;

	while (dq)
	{
		temp = dq;
		dq = (dq)-> next;
		free(temp);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	a_info;
	t_info	b_info;
	int		size;

	size = 0;
	if (argc < 2)
		return (0);
	init(&a_info.list, &a_info);
	init(&b_info.list, &b_info);
	count_num(argc, argv, &size, 0);
	push_a(argc, argv, &a_info, size);
	if (2 <= size && size <= 5)
		sort_small_num(&a_info, &b_info, size);
	a_to_b(&a_info, &b_info);
	b_to_a(&a_info, &b_info);
	free_all(a_info.list);
}
