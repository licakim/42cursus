/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:58:34 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/07 16:54:05 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

void	exec_cmd(t_info *a_info, t_info *b_info, char *str)
{
	if (ft_strcmp("sa", str) == 0)
		sa(a_info);
	else if (ft_strcmp("sb", str) == 0)
		sb(b_info);
	else if (ft_strcmp("pa", str) == 0)
		pa(a_info, b_info);
	else if (ft_strcmp("pb", str) == 0)
		pb(a_info, b_info);
	else if (ft_strcmp("ra", str) == 0)
		ra(a_info);
	else if (ft_strcmp("rb", str) == 0)
		rb(b_info);
	else if (ft_strcmp("rr", str) == 0)
		rr(a_info, b_info);
	else if (ft_strcmp("rra", str) == 0)
		rra(a_info);
	else if (ft_strcmp("rrb", str) == 0)
		rrb(b_info);
	else if (ft_strcmp("rrr", str) == 0)
		rrr(a_info, b_info);
	else
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

void	read_cmd(t_info *a_info, t_info *b_info)
{
	char	*str;
	char	*temp;

	str = get_next_line(0);
	while (str)
	{
		exec_cmd(a_info, b_info, str);
		temp = str;
		str = get_next_line(0);
		free(temp);
	}
}

void	check_sort(t_info *a_info, t_info *b_info, int *temp, int size)
{
	t_deque	*tmp;
	int		i;

	read_cmd(a_info, b_info);
	tmp = a_info->front;
	i = 0;
	while (tmp && i < size)
	{
		if (tmp->data != temp[i])
		{
			free_all(a_info->list);
			free(temp);
			ft_printf("KO\n");
			exit(1);
		}
		tmp = tmp -> next;
		i++;
	}
	free(temp);
	free_all(a_info->list);
	if (tmp == 0 && i == size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char *argv[])
{
	t_info	a_info;
	t_info	b_info;
	int		size;
	int		*temp;

	if (argc < 2)
		return (0);
	init(&a_info.list, &a_info);
	init(&b_info.list, &b_info);
	count_num(argc, argv, &size, 0);
	temp = push_a_bn(argc, argv, &a_info, size);
	check_sort(&a_info, &b_info, temp, size);
}
