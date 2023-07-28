/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:37:44 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/01/31 18:15:57 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	while (*haystack && len > n_len - 1)
	{
		if (!(ft_strncmp(haystack, needle, n_len)))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
