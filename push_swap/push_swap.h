/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:28:20 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/07 18:26:06 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"

# include <stdlib.h>

typedef struct s_deque
{
	int				data;
	int				command[2];
	struct s_deque	*next;
	struct s_deque	*prev;
}	t_deque;

typedef struct s_info
{
	t_deque	*list;
	t_deque	*front;
	t_deque	*rear;
	int		size;
	int		min;
}	t_info;

void	check_min(t_info *info, int add);
void	add_front(int add, t_info *info);
void	delete_front(t_info *info);
void	add_rear(int add, t_info *info);
void	delete_rear(t_info *info);
void	sa(t_info *a_info);
void	sb(t_info *b_info);
void	ss(t_info *a_info, t_info *b_info);
void	pa(t_info *a_info, t_info *b_info);
void	pb(t_info *a_info, t_info *b_info);
void	ra(t_info *a_info);
void	rb(t_info *b_info);
void	rr(t_info *a_info, t_info *b_info);
void	rra(t_info *a_info);
void	rrb(t_info *b_info);
void	rrr(t_info *a_info, t_info *b_info);
void	init(t_deque **dq, t_info *info);
int		check(int *temp, int n, int size);
void	swap(int *a, int *b);
void	quicksort(int left, int right, int *data);
void	a_to_b_size(t_info *a_info, int *pivot, int *size);
void	a_to_b_inner(t_info *a_info, t_info *b_info, int *pivot, int size);
void	a_to_b(t_info *a_info, t_info *b_info);
void	check_count(t_deque *cnt, t_info *dq_info, int n, int i);
int		get_count_to_min(t_info *a_info);
int		check_a_count_inner(t_deque *b, t_info *a_info, int *size);
void	check_a_count(t_deque *b, t_info *a_info);
int		abs_sum(int a, int b);
t_deque	*find_min(t_info *b_info);
void	move_min_up(t_info *a_info, t_info *b_info, int *cmd);
void	move_min_down(t_info *a_info, t_info *b_info, int *cmd);
void	move_min(t_info *a_info, t_info *b_info);
void	min_to_top(t_info *info, int min);
void	b_to_a(t_info *a_info, t_info *b_info);
void	isvalid(int *temp, int n);
void	sort_three_num(t_info *a_info, int min);
void	sort_four_num(t_info *a_info, t_info *b_info);
void	sort_five_num(t_info *a_info, t_info *b_info);
void	sort_two_num(t_info *a_info);
void	count_num(int argc, char *argv[], int *size, int i);
int		free_all(t_deque *dq);
int		*malloc_array(int size);
void	push_a(int argc, char *argv[], t_info	*a_info, int size);
void	check_if_sorted(int *temp, int size);
void	sort_small_num(t_info *a_info, t_info *b_info, int size);
#endif
