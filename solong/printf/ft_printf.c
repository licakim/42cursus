/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:18:05 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/01/28 22:38:18 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	check_format(char format)
{
	if (format == 'c' || format == 'd' || format == 'i' || format == 'x')
		return (1);
	if (format == 'X' || format == 'u' || format == 's' || \
						format == 'p' || format == '%')
		return (1);
	return (0);
}

int	printf_main(const char *format, va_list ap)
{
	if (*(format + 1) == 'c')
		return (printf_char(ap));
	else if ((*(format + 1) == 'd' || *(format + 1) == 'i' || \
			*(format + 1) == 'x' || *(format + 1) == 'X'))
		return (printf_dix(ap, *(format + 1)));
	else if (*(format + 1) == 'u')
		return (ft_put_unbr_fd(va_arg(ap, unsigned int), 1));
	else if (*(format + 1) == 's')
		return (ft_putendl(va_arg(ap, char *), 1));
	else if (*(format + 1) == 'p')
		return (put_add(va_arg(ap, void *)));
	else
		return (write(1, format, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				size;
	int				temp;

	size = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && check_format(*(format + 1)))
		{
			temp = printf_main(format, ap);
			if (temp == -1)
				return (-1);
			format = format + 2;
		}
		else
		{
			temp = write(1, format++, 1);
			if (temp == -1)
				return (-1);
		}
		size += temp;
	}
	va_end(ap);
	return (size);
}
