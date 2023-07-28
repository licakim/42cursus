/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:39:16 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/02/06 18:42:57 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"solong.h"

void	put_img(t_map *map)
{
	map -> img.w_h = 64;
	map -> img.player = mlx_xpm_file_to_image(map -> mlx, \
		"textures/teruteru.xpm", &(map -> img.w_h), &(map -> img.w_h));
	map -> img.wall = mlx_xpm_file_to_image(map -> mlx, \
		"textures/p_tile.xpm", &(map -> img.w_h), &(map -> img.w_h));
	map -> img.empty = mlx_xpm_file_to_image(map -> mlx, \
		"textures/white.xpm", &(map -> img.w_h), &(map -> img.w_h));
	map -> img.collect = mlx_xpm_file_to_image(map -> mlx, \
		"textures/collect2.xpm", &(map -> img.w_h), &(map -> img.w_h));
	map -> img.exit = mlx_xpm_file_to_image(map -> mlx, \
		"textures/home.xpm", &(map -> img.w_h), &(map -> img.w_h));
}

void	print_img(t_map *map, void *img, int i, int j)
{
	mlx_put_image_to_window(map -> mlx, map -> win, \
			img, map -> img.w_h * j, map -> img.w_h * i);
}

void	print_map_inner(t_map *map, int i, int j)
{
	if (map -> arr[i][j] == '0')
		print_img(map, map -> img.empty, i, j);
	if (map -> arr[i][j] == '1')
	{
		print_img(map, map -> img.empty, i, j);
		print_img(map, map -> img.wall, i, j);
	}
	if (map -> arr[i][j] == 'C')
	{
		print_img(map, map -> img.empty, i, j);
		print_img(map, map -> img.collect, i, j);
	}
	if (map -> arr[i][j] == 'P')
	{
		print_img(map, map -> img.empty, i, j);
		print_img(map, map -> img.player, i, j);
	}
	if (map -> arr[i][j] == 'E')
	{
		print_img(map, map -> img.empty, i, j);
		print_img(map, map -> img.exit, i, j);
	}
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map -> height)
	{
		j = -1;
		while (++j < map -> width)
			print_map_inner(map, i, j);
	}
}
