/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:44:44 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/12/21 20:53:30 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{	
	size_t	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dest;
	char	*temp;

	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!dest)
		return (0);
	temp = dest;
	while (*s1)
		*dest++ = *s1++;
	while (*s2)
		*dest++ = *s2++;
	*dest = 0;
	return (temp);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	init(t_list **head)
{
	if (!*head)
	{
		*head = (t_list *)malloc(sizeof(t_list));
		if (!*head)
			return (1);
		(*head)-> next = 0;
	}
	return (0);
}

void	del_node(t_list	*cur, t_list **head)
{
	if (cur -> s)
		free(cur->s);
	cur->prev-> next = cur->next;
	if (cur->next)
		cur->next->prev = cur->prev;
	free(cur);
	cur = 0;
	if (!((*head)->next))
	{
		free(*head);
		*head = 0;
	}
}
