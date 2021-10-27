/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:47:11 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/27 10:42:01 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(char *file, t_map *map)
{
	int		fd;
	int		i;
	int		len;
	int		prev_len;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(2);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		free(line);
		if (i++ != 0)
			if (len != prev_len)
				error(3);
		prev_len = len;
		line = get_next_line(fd);
	}
	close(fd);
	map->x = len;
	map->y = i;
}

char	**read_map(char *file, t_map *map)
{
	char	**line;
	int		fd;
	int		i;

	i = 0;
	line = ft_calloc(map->y + 1, sizeof(char *));
	if (line)
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
			error(2);
		while (i < map->y)
			line[i++] = get_next_line(fd);
		close(fd);
		return (line);
	}
	return (0);
}

int	is_valid_map(t_program *mlx, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->y)
	{
		j = -1;
		while (++j < map->x)
		{
			if (((i == 0) || (i == map->y - 1) || (j == 0)
					|| (j == map->x - 1)) && (mlx->map[i][j] != '1'))
				return (0);
			else if (mlx->map[i][j] == 'C')
				map->col++;
			else if (mlx->map[i][j] == 'E')
				map->exit++;
			else if (mlx->map[i][j] == 'P')
				map->pos++;
		}
	}
	return ((map->col > 0) & (map->exit > 0) & (map->pos == 1));
}

static void	print_map_aux(t_program *mlx, int i, int j)
{
	if (mlx->map[i][j] == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->grass, 64 * j, 64 * i);
	else
	{
		mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->water, 64 * j, 64 * i);
		if (mlx->map[i][j] == 'P')
		{
			mlx_put_image_to_window(mlx->ptr, mlx->wdw,
				mlx->cat_f[1], 64 * j, 64 * i);
			mlx->x = j;
			mlx->y = i;
		}
		else if (mlx->map[i][j] == 'C')
		{
			mlx_put_image_to_window(mlx->ptr, mlx->wdw,
				mlx->mush, 64 * j, 64 * i);
			mlx->obj++;
		}
		else if (mlx->map[i][j] == 'E')
			mlx_put_image_to_window(mlx->ptr, mlx->wdw,
				mlx->hole, 64 * j, 64 * i);
	}
}

void	print_map(t_program *mlx, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			print_map_aux(mlx, i, j);
			j++;
		}
		i++;
	}
}
