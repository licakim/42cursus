/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:19:44 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/01/31 18:15:53 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	size_t	n;
	size_t	len;
	char	*temp;

	n = 0;
	len = ft_strlen(s);
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	while (s[n])
	{
		temp[n] = f(n, s[n]);
		n++;
	}
	temp[n] = 0;
	return (temp);
}
