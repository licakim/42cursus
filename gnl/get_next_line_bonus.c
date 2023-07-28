/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:51:30 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/12/17 16:37:16 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*find_fd(t_list *head, int fd)
{
	t_list	*temp;
	t_list	*new;

	temp = head;
	while (temp->next)
	{
		temp = temp -> next;
		if (temp -> f_fd == fd)
			return (temp);
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new -> f_fd = fd;
	new -> next = 0;
	new -> s = 0;
	new -> prev = temp;
	temp -> next = new;
	return (new);
}

int	find_oneline(char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*one_line(char **s)
{
	char	*line;
	char	*temp;
	int		ind;

	ind = find_oneline(*s);
	line = ft_strdup(*s);
	if (ind != -1)
		line[ind + 1] = 0;
	if (line)
	{
		temp = *s;
		*s = ft_strdup(*s + ft_strlen(line));
		free(temp);
		if (!*s)
			return (0);
		return (line);
	}
	return (0);
}

char	*read_file(char *s, int fd)
{
	char			*buf;
	char			*temp;
	ssize_t			rsize;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	rsize = read(fd, buf, BUFFER_SIZE);
	while (rsize > 0)
	{
		buf[rsize] = 0;
		temp = s;
		s = ft_strjoin(temp, buf);
		free(temp);
		if (!s || find_oneline(s) != -1)
			break ;
		rsize = read(fd, buf, BUFFER_SIZE);
	}
	if (rsize < 0)
	{
		free(s);
		s = 0;
	}
	free(buf);
	return (s);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*cur;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (init(&head))
		return (0);
	cur = find_fd(head, fd);
	if (!cur)
		return (0);
	cur -> s = read_file(cur->s, fd);
	if (!(cur->s))
	{
		del_node(cur, &head);
		return (0);
	}
	if (*(cur->s))
	{
		line = one_line(&(cur->s));
		if (line)
			return (line);
	}
	del_node(cur, &head);
	return (0);
}
