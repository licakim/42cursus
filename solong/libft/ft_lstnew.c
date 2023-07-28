/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:50:36 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/11/27 16:38:38 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *content)
{	
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new -> content = content;
	new -> next = 0;
	return (new);
}
