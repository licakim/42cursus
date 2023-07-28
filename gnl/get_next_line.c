/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:30:21 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/02/14 13:42:21 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

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

char	*one_line(char **s)
{
	char	*line;
	char	*temp;
	int		ind;

	ind = find_oneline(*s);
	if (ind == -1)
		line = ft_strdup(*s);
	else
		line = ft_substr(*s, 0, ind + 1);
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

char	*get_next_line(int fd)
{
	char			*line;
	static char		*s;

	line = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	s = read_file(s, fd);
	if (!s)
		return (0);
	if (*s)
	{
		line = one_line(&s);
		if (line)
			return (line);
	}
	free(s);
	s = 0;
	return (line);
}
