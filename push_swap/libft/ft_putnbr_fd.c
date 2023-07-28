/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:24:20 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/12/17 21:44:13 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	print_nbr(int n, int fd)
{
	char	c;

	if (n / 10 != 0)
		print_nbr(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		print_nbr(-n, fd);
	}	
	else
		print_nbr(n, fd);
}
