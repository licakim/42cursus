/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:16:41 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/01/03 13:22:35 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdarg.h>
# include<unistd.h>

int		print_nbr(unsigned int n, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_put_unbr_fd(unsigned int n, int fd);
int		ft_putendl_fd(char *s, int fd);
int		print_hexa(unsigned int n, int fd, int flag);
int		print_add(unsigned long long a, int fd);
int		put_add(void	*p);
int		printf_dix(va_list ap, char format);
int		printf_char(va_list ap);
int		ft_printf(const char *format, ...);

#endif
