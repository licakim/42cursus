/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:45:06 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/02/06 17:53:34 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_check(t_map *map, t_check *check)
{
	int	i;
	int	j;

	i = -1;
	check -> c_x = map -> p_x;
	check -> c_y = map -> p_y;
	check -> c_collect = map -> m_collect;
	check -> c_exit = 0;
	check -> check_visit = malloc(sizeof(int *) * map -> height);
	if (!check -> check_visit)
		error_msg("");
	while (++i < map -> height)
	{
		j = -1;
		check -> check_visit[i] = malloc(sizeof(int) * map -> width);
		if (!check -> check_visit[i])
			error_msg("");
		while (++j < map -> width)
		{
			if (map -> arr[i][j] == '1')
				check -> check_visit[i][j] = 1;
			else
				check -> check_visit[i][j] = 0;
		}
	}
}

void	dfs_check(t_map *map, t_check *check, int x, int y)
{
	const int	move_x[4] = {-1, 1, 0, 0};
	const int	move_y[4] = {0, 0, -1, 1};
	int			i;

	check -> check_visit[x][y] = 1;
	if (map -> arr[x][y] == 'C')
		(check -> c_collect)--;
	if (map -> arr[x][y] == 'E')
	{
		check -> c_exit = 1;
		return ;
	}
	i = 0;
	while (i < 4)
	{
		if (check -> check_visit[x + move_x[i]][y + move_y[i]] != 1)
			dfs_check(map, check, x + move_x[i], y + move_y[i]);
		i++;
	}
}

void	dfs(t_map *map)
{
	t_check	check;
	int		i;

	i = 0;
	init_check(map, &check);
	dfs_check(map, &check, check.c_x, check.c_y);
	if (check.c_exit != 1 || check.c_collect != 0)
		error_msg("경로가 없어 유효하지 않은 맵입니다.\n");
	while (i < map -> height)
		free(check.check_visit[i++]);
	free(check.check_visit);
}
