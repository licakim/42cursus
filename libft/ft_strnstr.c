/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:37:44 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/11/24 21:09:11 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
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
