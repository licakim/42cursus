/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:57:47 by hyunjki2          #+#    #+#             */
/*   Updated: 2023/02/06 18:41:48 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map -> height)
		free(map -> arr[i]);
	free(map -> arr);
}

void	check_map_inner(t_map *map, int i, int j)
{
	if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
	{
		if (map -> arr[i][j] != '1')
		{
			free_map(map);
			error_msg("벽이 뚫려 있습니다\n");
		}
	}
	else if (map -> arr[i][j] == 'C')
		(map -> m_collect)++;
	else if (map -> arr[i][j] == 'E')
		(map -> m_exit)++;
	else if (map -> arr[i][j] == 'P')
	{
		map -> p_x = i;
		map -> p_y = j;
		(map -> m_start)++;
	}
	else if (!(map -> arr[i][j] == '0' || map -> arr[i][j] == '1'))
	{
		free_map(map);
		error_msg("허용된 문자 외의 문자가 들어왔습니다\n");
	}
}

void	check_map(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	map -> arr = ft_split(map -> sv_map, '\n');
	if (!map -> sv_map)
		error_msg("");
	free(map -> sv_map);
	while (++i < map -> height)
	{
		j = -1;
		while (++j < map -> width)
			check_map_inner(map, i, j);
	}
	if (map -> m_exit != 1 || map -> m_start != 1 || map -> m_collect < 1)
	{
		free_map(map);
		error_msg("exit, start, collectible의 개수가 올바르지 않습니다\n");
	}
}

void	put_map(int fd, t_map *map)
{
	char	*temp;
	char	*prev;

	while (1)
	{
		temp = get_next_line(fd);
		if (temp == 0)
			break ;
		if (ft_len(temp) - 1 != map -> width)
		{
			free(temp);
			free(map -> sv_map);
			error_msg("직사각형이 아닙니다.\n");
		}
		(map -> height)++;
		prev = map -> sv_map;
		map -> sv_map = join_line(map -> sv_map, temp);
		free(temp);
		free(prev);
	}
	if (map -> height < 3)
	{	
		free(map -> sv_map);
		error_msg("맵의 높이가 충분하지 않습니다\n");
	}
}

void	init_map(char *file_name, t_map *map)
{
	char	*temp;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_msg("파일 open 실패\n");
	map -> width = 0;
	map -> height = 0;
	map -> m_collect = 0;
	map -> m_exit = 0;
	map -> m_start = 0;
	map -> sv_map = 0;
	temp = get_next_line(fd);
	if (temp == 0)
		error_msg("빈 파일 입니다\n");
	map -> width = ft_len(temp) - 1;
	if (map -> width < 3)
	{
		free(temp);
		error_msg("맵 너비가 충분하지 않습니다\n");
	}
	map -> height = 1;
	map -> sv_map = join_line(map -> sv_map, temp);
	free(temp);
	put_map(fd, map);
}
