/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:57:22 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/11/27 16:38:53 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*cnt;

	cnt = *lst;
	while (cnt)
	{
		temp = cnt -> next;
		del(cnt -> content);
		free(cnt);
		cnt = temp;
	}
	*lst = 0;
}
