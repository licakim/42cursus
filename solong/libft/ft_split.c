/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:15:18 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/01/31 18:15:35 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_all(char **strs, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

static	int	count_strs(char *s, char c)
{
	int	count;
	int	start;

	count = 0;
	start = 0;
	while (*s)
	{
		if (start == 0 && *s != c)
		{
			start = 1;
			count++;
		}
		else if (start == 1 && *s == c)
		{
			start = 0;
		}
		s++;
	}
	return (count);
}

int	put_str(char **strs, int j, char *start, int len)
{			
	strs[j] = malloc(sizeof(char) * (len + 1));
	if (!strs[j])
	{
		free_all(strs, j);
		return (0);
	}
	ft_strlcpy(strs[j], start, len + 1);
	return (1);
}

int	put_strs(char **strs, char *s, char c, int start)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	j = 0;
	while (s[++i])
	{
		if (start == -1 && s[i] != c)
			start = i;
		else if (start != -1 && s[i] == c)
		{
			len = i - start;
			if (!put_str(strs, j++, s + start, len))
				return (0);
			start = -1;
		}
	}
	if (start != -1)
	{
		len = i - start;
		if (!put_str(strs, j, s + start, len))
			return (0);
	}
	return (1);
}

char	**ft_split(char *s, char c)
{
	char	**strs;
	int		len;

	len = count_strs(s, c);
	strs = (char **)malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return (0);
	strs[len] = 0;
	if (!put_strs(strs, s, c, -1))
		return (0);
	return (strs);
}
