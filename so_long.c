/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:21:26 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/18 15:35:17 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int i)
{
	if (i == 0)
		write(1, "Error! Number of arguments not valid", 36);
	else if (i == 1)
		write(1, "Error! Can't open map file", 26);
	else if (i == 2)
		write(1, "Error! Map not valid", 20);
	write(1, "\n", 1);
	exit(0);
}

void	get_map_size(char *file, t_map *map_size)
{
	int		fd;
	int		i;
	int		len;
	int		prev_len;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd >= 0)
	{
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
}

char	**read_map(char *file, t_map map_size)
{
	char	**map;
	int		fd;
	int		i;
	
	i = 0;
	map = ft_calloc(map_size.y, sizeof(char *));
	if (map)
	{
		fd = open(file, O_RDONLY);
		if (fd >= 0)
		{
			while (i < map_size.y)
				map[i++] = get_next_line(fd);
			close(fd);
			map[i] = 0;
			return (map);
		}
		else
			error(1);
	}
	return (0);
}

int	is_valid_map(char **map, t_map map_size)
{
	int	i;
	int	j;

	i = 0;
	if (map)
	{
		while (i < map_size.y)
		{
			j = 0;
			while (j < map_size.x)
			{
				
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_map	map_size;
	char	**map;

	if (argc != 2)
		error(0);
	else
	{
		get_map_size(argv[1], &map_size);
		map = read_map(argv[1], map_size);
		if (!is_valid_map(map, map_size))
			error(2);
		else
		{
			//Juego
		}
	}
	return (0);
}