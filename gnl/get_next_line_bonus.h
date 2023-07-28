/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:45:15 by hyunjki2          #+#    #+#             */
/*   Updated: 2022/12/22 15:36:50 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include<stddef.h>
# include<unistd.h>
# include<stdlib.h>

typedef struct s_list
{
	struct s_list	*prev;
	struct s_list	*next;
	int				f_fd;
	char			*s;
}	t_list;

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
int		init(t_list **head);
void	del_node(t_list	*cur, t_list **head);

#endif
