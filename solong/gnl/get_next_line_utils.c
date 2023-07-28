/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:43:53 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/02/04 17:25:15 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(char *s)
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

char	*ft_strjoin(char *s1, char *s2)
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

char	*ft_strdup(char *s1)
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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;
	size_t	n;

	size = ft_strlen(s);
	if (size <= start)
		return (ft_strdup(""));
	if (size - start < len)
		len = size - start;
	n = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (n < len && s[start + n] != 0)
	{
		str[n] = s[start + n];
		n++;
	}
	str[n] = 0;
	return (str);
}
