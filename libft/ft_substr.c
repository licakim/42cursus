/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:47:19 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/11/27 16:36:35 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
