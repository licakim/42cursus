/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:14:12 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/11/28 22:58:23 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	if (s < d)
	{
		d = d + len - 1;
		s = s + len - 1;
		while (len > 0)
		{
			*d-- = *s--;
			len--;
		}
	}
	else if (s > d)
	{
		while (len > 0)
		{
			*d++ = *s++;
			len--;
		}
	}
	return (dst);
}
