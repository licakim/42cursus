/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:18:16 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/11/28 18:42:24 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size;

	size = ft_strlen(src);
	if (dstsize == 0)
		return (size);
	while (*src && 1 < dstsize)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}	
	*dst = 0;
	return (size);
}
