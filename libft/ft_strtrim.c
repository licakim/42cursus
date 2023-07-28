/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:30:17 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/12/03 19:57:55 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char const *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*dest;
	char	*temp;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	temp = dest;
	while (*s1 && n > 0)
	{
		*dest++ = *s1++;
		n--;
	}
	*dest = 0;
	return (temp);
}

const char const	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	n;
	size_t	start;

	n = 0;
	start = 0;
	len = ft_strlen(s1);
	while (n < len)
	{
		if (check(set, s1[n]))
			n++;
		else
			break ;
	}
	start = n;
	while (len - 1 > n)
	{
		if (check(set, s1[len - 1]))
			len--;
		else
			break ;
	}
	return (ft_strndup(s1 + start, len - start));
}
