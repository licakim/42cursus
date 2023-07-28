/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:44:53 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/01/28 22:37:54 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_add(unsigned long long a, int fd)
{
	int			size;
	static int	temp;

	size = 0;
	temp = 0;
	if (a / 16 != 0)
		size = print_add(a / 16, fd);
	if (temp == -1)
		return (-1);
	temp = write(fd, &"0123456789abcdef"[a % 16], 1);
	size += temp;
	return (size);
}

int	put_add(void	*p)
{
	unsigned long long	add;
	int					size;
	int					temp;

	add = (unsigned long long)p;
	if (write(1, "0x", 2) == -1)
		return (-1);
	temp = print_add(add, 1);
	if (temp == -1)
		return (-1);
	size = 2 + temp;
	return (size);
}

int	printf_dix(va_list ap, char format)
{
	int	k;

	k = va_arg(ap, int);
	if (format == 'd' || format == 'i')
		return (ft_putnbr(k, 1));
	else if (format == 'x')
		return (print_hexa(k, 1, 0));
	else
		return (print_hexa(k, 1, 1));
}

int	printf_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	return (write(1, &c, 1));
}
