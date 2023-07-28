/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:34:40 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/11/28 18:42:54 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	n = d_len;
	if (dstsize == 0 || d_len > dstsize)
		return (s_len + dstsize);
	dst = dst + d_len;
	while (n + 1 < dstsize && *src)
	{
		*dst = *src;
		dst++;
		src++;
		n++;
	}
	*dst = 0;
	return (d_len + s_len);
}
