/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:47:11 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/20 14:18:54 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(char *file, t_map *map_size)
{
	int		fd;
	int		i;
	int		len;
	int		prev_len;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(1);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		free(line);
		if (i++ != 0)
			if (len != prev_len)
				error(2);
		prev_len = len;
		line = get_next_line(fd);
	}
	close(fd);
	map_size->x = len;
	map_size->y = i;
}

char	**read_map(char *file, t_map map_size)
{
	char	**map;
	int		fd;
	int		i;

	i = 0;
	map = ft_calloc(map_size.y + 1, sizeof(char *));
	if (map)
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
			error(1);
		while (i < map_size.y)
			map[i++] = get_next_line(fd);
		map[i] = 0;
		close(fd);
		return (map);
	}
	return (0);
}

static void	are_map_elements(char a, int *pos, int *col, int *exit)
{
	if (a == 'C')
		*col += 1;
	else if (a == 'E')
		*exit += 1;
	else if (a == 'P')
		*pos += 1;
}

int	is_valid_map(char **map, t_map map_size)
{
	int	i;
	int	j;
	int	pos;
	int	col;
	int	exit;

	i = -1;
	pos = 0;
	col = 0;
	exit = 0;
	if (map)
	{
		while (++i < map_size.y)
		{
			j = -1;
			while (++j < map_size.x)
			{
				if (((i == 0) || (i == map_size.y - 1) || (j == 0)
						|| (j == map_size.x - 1)) && (map[i][j] != '1'))
					return (0);
				are_map_elements(map[i][j], &pos, &col, &exit);
			}
		}
	}
	return ((col > 0) & (exit > 0) & (pos > 0));
}
