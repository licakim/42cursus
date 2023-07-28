/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:07:12 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/01/31 18:15:40 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(char *s1)
{
	char	*dest;
	char	*temp;
	size_t	len;

	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	temp = dest;
	while (*s1)
	{
		*dest++ = *s1++;
	}
	*dest = 0;
	return (temp);
}
