/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:57:59 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/12/28 17:08:03 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	print_nbr(unsigned int n, int fd)
{
	char		c;
	int			size;
	static int	temp;

	size = 0;
	temp = 0;
	if (n / 10 != 0)
		size = print_nbr(n / 10, fd);
	if (temp == -1)
		return (-1);
	c = n % 10 + '0';
	temp = write(fd, &c, 1);
	size += temp;
	return (size);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	size;
	int	temp;

	size = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	else if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		size++;
		n = -n;
	}
	temp = print_nbr(n, fd);
	if (temp == -1)
		return (-1);
	size += temp;
	return (size);
}

int	ft_put_unbr_fd(unsigned int n, int fd)
{
	int	size;

	size = print_nbr(n, fd);
	return (size);
}

int	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (write(1, &"(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		if (write(fd, &s[i++], 1) == -1)
			return (-1);
	}
	return (i);
}

int	print_hexa(unsigned int n, int fd, int flag)
{
	int			size;
	static int	temp;

	size = 0;
	temp = 0;
	if (flag == 0)
	{
		if (n / 16 != 0)
			size = print_hexa(n / 16, fd, 0);
		if (temp == -1)
			return (-1);
		temp = write(fd, &"0123456789abcdef"[n % 16], 1);
		size += temp;
	}
	if (flag == 1)
	{
		if (n / 16 != 0)
			size = print_hexa(n / 16, fd, 1);
		if (temp == -1)
			return (-1);
		temp = write(fd, &"0123456789ABCDEF"[n % 16], 1);
		size += temp;
	}
	return (size);
}
