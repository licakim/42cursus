/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:00:06 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/05/07 18:26:46 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_deque
{
	int				data;
	struct s_deque	*next;
	struct s_deque	*prev;
}	t_deque;

typedef struct s_info
{
	t_deque	*list;
	t_deque	*front;
	t_deque	*rear;
	int		size;
}	t_info;

int		*push_a_bn(int argc, char *argv[], t_info	*a_info, int size);
int		*malloc_array(int size);
void	exec_cmd(t_info *a_info, t_info *b_info, char *str);
void	check_if_empty(char *str);
void	count_num(int argc, char *argv[], int *size, int i);
void	read_cmd(t_info *a_info, t_info *b_info);
void	check_sort(t_info *a_info, t_info *b_info, int *temp, int size);
int		ft_strcmp(char *s1, char *s2);
int		free_all(t_deque *dq);
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
void	check_if_sorted(int *temp, int size);
#endif
