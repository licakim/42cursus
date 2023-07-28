/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:39:01 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/02/06 18:42:08 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "./gnl/get_next_line.h"

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img
{
	void	*player;
	void	*wall;
	void	*collect;
	void	*empty;
	void	*exit;
	int		w_h;
}	t_img;

typedef struct s_map
{
	void			*mlx;
	void			*win;
	char			**arr;
	char			*sv_map;
	int				width;
	int				height;
	int				m_collect;
	int				m_exit;
	int				m_start;
	int				p_x;
	int				p_y;
	int				p_move;
	struct s_img	img;
}	t_map;

typedef struct s_check
{
	int	**check_visit;
	int	c_x;
	int	c_y;
	int	c_collect;
	int	c_exit;
}	t_check;

int		end_game(void);
int		success_game(void);
void	move_up(t_map *map, int x, int y);
void	move_down(t_map *map, int x, int y);
void	move_left(t_map *map, int x, int y);
void	move_right(t_map *map, int x, int y);
int		key_press(int key_code, t_map *map);
int		ft_len(const char *s);
void	error_msg(char *str);
void	check_map(t_map *map);
void	check_map_inner(t_map *map, int i, int j);
void	check_file_name(char *file_name);
void	put_map(int fd, t_map *map);
void	init_map(char *file_name, t_map *map);
void	put_img(t_map *map);
void	print_map(t_map *map);
void	init_check(t_map	*map, t_check	*check);
void	dfs_check(t_map *map, t_check *check, int x, int y);
void	dfs(t_map *map);
void	free_map(t_map *map);
char	*join_line(char *s1, char *s2);

#endif
