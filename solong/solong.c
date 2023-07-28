/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:38:02 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/02/06 18:40:56 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_file_name(char *file_name)
{
	int	len;

	len = ft_len(file_name);
	if (len < 5 || file_name[len - 1] != 'r' || file_name[len - 2] != 'e' \
					|| file_name[len - 3] != 'b' || file_name[len - 4] != '.')
		error_msg("파일 이름이 올바르지 않습니다\n");
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		error_msg("인자의 개수가 2개가 아닙니다\n");
	check_file_name(argv[1]);
	init_map(argv[1], &map);
	check_map(&map);
	dfs(&map);
	map.mlx = mlx_init();
	if (map.mlx == 0)
		error_msg("mlx init 실패\n");
	map.win = mlx_new_window(map.mlx, \
			64 * map.width, 64 * map.height, "teruteru");
	if (map.win == 0)
		error_msg("window 생성 실패\n");
	put_img(&map);
	print_map(&map);
	map.p_move = 0;
	mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, &key_press, &map);
	mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, &end_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
