/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:36:48 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/06/12 17:38:48 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include<unistd.h>
# include<signal.h>
# include<stdlib.h>

# include "./printf/ft_printf.h"

void	send_sig(pid_t pid, char *str, int i);
int		ft_strlen(char	*str);
int		ft_atoi(const char *str);
int		ft_isdigit(int num);

#endif
