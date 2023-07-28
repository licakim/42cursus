/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:08:47 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/02/06 18:52:37 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"solong.h"

void	move_up(t_map *map, int x, int y)
{
	if (map -> arr[x - 1][y] == 'C')
	{
		map -> arr[x - 1][y] = '0';
		map -> m_collect--;
	}
	else if (map -> arr[x - 1][y] == 'E')
	{
		if (map -> m_collect == 0)
			success_game();
	}
	if (map -> arr[x - 1][y] != '1' && map -> arr[x - 1][y] != 'E')
	{
		map -> arr[x][y] = '0';
		map -> p_x = x - 1;
		map -> p_move++;
		if (ft_printf("move: %d\n", map -> p_move) == -1)
			error_msg("");
		mlx_put_image_to_window(map -> mlx, map -> win, \
			map -> img.empty, map -> img.w_h * y, map -> img.w_h * x);
		mlx_put_image_to_window(map -> mlx, map -> win, \
			map -> img.empty, map -> img.w_h * y, map -> img.w_h * (x -1));
		mlx_put_image_to_window(map -> mlx, map -> win, \
			map -> img.player, map -> img.w_h * y, map -> img.w_h * (x - 1));
	}
}

void	move_down(t_map *map, int x, int y)
{
	if (map -> arr[x + 1][y] == 'C')
	{
		map -> arr[x + 1][y] = '0';
		map -> m_collect--;
	}
	else if (map -> arr[x + 1][y] == 'E')
	{
		if (map -> m_collect == 0)
			success_game();
	}
	if (map -> arr[x + 1][y] != '1' && map -> arr[x + 1][y] != 'E')
	{
		map -> arr[x][y] = '0';
		map -> p_x = x + 1;
		map -> p_move++;
		if (ft_printf("move: %d\n", map -> p_move) == -1)
			error_msg("");
		mlx_put_image_to_window(map -> mlx, map -> win, \
			map -> img.empty, map -> img.w_h * y, map -> img.w_h * x);
		mlx_put_image_to_window(map -> mlx, map -> win, \
			map -> img.empty, map -> img.w_h * y, map -> img.w_h * (x + 1));
		mlx_put_image_to_window(map -> mlx, map -> win, \
			map -> img.player, map -> img.w_h * y, map -> img.w_h * (x + 1));
	}
}

void	move_left(t_map *map, int x, int y)
{
	if (map -> arr[x][y - 1] == 'C')
	{
		map -> arr[x][y] = '0';
		map -> m_collect--;
	}
	else if (map -> arr[x][y - 1] == 'E')
	{
		if (map -> m_collect == 0)
			success_game();
	}
	if (map -> arr[x][y - 1] != '1' && map -> arr[x][y - 1] != 'E')
	{
		map -> arr[x][y] = '0';
		map -> p_y = y - 1;
		map -> p_move++;
		if (ft_printf("move: %d\n", map -> p_move) == -1)
			error_msg("");
		mlx_put_image_to_window(map -> mlx, map -> win, \
			map -> img.empty, map -> img.w_h * y, map -> img.w_h * x);
		mlx_put_image_to_window(map -> mlx, map -> win, \
			map -> img.empty, map -> img.w_h * (y - 1), map -> img.w_h * x);
		mlx_put_image_to_window(map -> mlx, map -> win, \
			map -> img.player, map -> img.w_h * (y - 1), map -> img.w_h * x);
	}
}

void	move_right(t_map *map, int x, int y)
{
	if (map -> arr[x][y + 1] == 'C')
	{
		map -> arr[x][y + 1] = '0';
		map -> m_collect--;
	}
	else if (map -> arr[x][y + 1] == 'E')
	{
		if (map -> m_collect == 0)
			success_game();
	}
	if (map -> arr[x][y + 1] != '1' && map -> arr[x][y + 1] != 'E')
	{
		map -> arr[x][y] = '0';
		map -> p_y = y + 1;
		map -> p_move++;
		if (ft_printf("move: %d\n", map -> p_move) == -1)
			error_msg("");
		mlx_put_image_to_window(map -> mlx, map -> win, \
			map -> img.empty, map -> img.w_h * y, map -> img.w_h * x);
		mlx_put_image_to_window(map -> mlx, map -> win, \
			map -> img.empty, map -> img.w_h * (y + 1), map -> img.w_h * x);
		mlx_put_image_to_window(map -> mlx, map -> win, \
			map -> img.player, map -> img.w_h * (y + 1), map -> img.w_h * x);
	}
}

int	key_press(int key_code, t_map *map)
{
	if (key_code == KEY_ESC)
		end_game();
	if (key_code == KEY_W)
		move_up(map, map -> p_x, map -> p_y);
	if (key_code == KEY_S)
		move_down(map, map -> p_x, map -> p_y);
	if (key_code == KEY_A)
		move_left(map, map -> p_x, map -> p_y);
	if (key_code == KEY_D)
		move_right(map, map -> p_x, map -> p_y);
	return (0);
}
