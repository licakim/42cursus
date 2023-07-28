/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:40:31 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/11/27 16:41:32 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr(char *str, int count, long long nb)
{
	if (nb == 0)
		str[0] = 0 + '0';
	while (nb != 0)
	{
		str[--count] = nb % 10 + '0';
		nb = nb / 10;
	}
}

int	count_len(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			count;
	long long	nb;
	char		*str;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		count = count_len(nb) + 1;
		str = (char *)malloc(sizeof(char) * (count + 1));
		if (!str)
			return (0);
		str[0] = '-';
	}
	else
	{
		count = count_len(nb);
		str = (char *)malloc(sizeof(char) * (count + 1));
		if (!str)
			return (0);
	}
	str[count] = 0;
	ft_putnbr(str, count, nb);
	return (str);
}
