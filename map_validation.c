/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:47:11 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/22 10:23:59 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(char *file, t_map *size)
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
	size->x = len;
	size->y = i;
}

char	**read_map(char *file, t_map size)
{
	char	**map;
	int		fd;
	int		i;

	i = 0;
	map = ft_calloc(size.y + 1, sizeof(char *));
	if (map)
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
			error(1);
		while (i < size.y)
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

int	is_valid_map(char **map, t_map size)
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
		while (++i < size.y)
		{
			j = -1;
			while (++j < size.x)
			{
				if (((i == 0) || (i == size.y - 1) || (j == 0)
						|| (j == size.x - 1)) && (map[i][j] != '1'))
					return (0);
				are_map_elements(map[i][j], &pos, &col, &exit);
			}
		}
	}
	return ((col > 0) & (exit > 0) & (pos > 0));
}
