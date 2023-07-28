/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:45:21 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/02/04 17:25:58 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!d && !s && n > 0)
		return (dst);
	while (n-- > 0)
	{
		*d++ = *s++;
	}
	return (dst);
}
