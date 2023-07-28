/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:56:34 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/12/05 16:43:39 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*add_newlst(t_list *lst, void *(*f)(void *), \
	void (*del)(void *), t_list *head)
{
	t_list	*temp;
	t_list	*new;

	new = head;
	while (lst)
	{
		temp = malloc(sizeof(t_list));
		if (!temp)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		temp -> content = f(lst -> content);
		temp -> next = 0;
		ft_lstadd_back(&new, temp);
		new = new -> next;
		lst = lst -> next;
	}
	return (head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;

	if (!lst)
		return (0);
	head = malloc(sizeof(t_list));
	if (!head)
		return (0);
	head -> content = f(lst -> content);
	head -> next = 0;
	lst = lst -> next;
	return (add_newlst(lst, f, del, head));
}
