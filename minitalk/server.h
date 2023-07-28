/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:07:54 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/06/12 17:37:33 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include<unistd.h>
# include<signal.h>
# include "./printf/ft_printf.h"

typedef struct s_char
{
	char			c;
	int				bit_idx;
}	t_char;

void	handler(int sig);

#endif
