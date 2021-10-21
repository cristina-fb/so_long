/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:21:26 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/21 14:43:13 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int i)
{
	if (i == 0)
		write(1, "Error\nNumber of arguments not valid", 35);
	else if (i == 1)
		write(1, "Error\nCan't open map file", 25);
	else if (i == 2)
		write(1, "Error\nMap not valid", 19);
	else if (i == 3)
		write(1, "Error\nMap size too big", 22);
	write(1, "\n", 1);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_map	size;
	char	**map;

	if (argc != 2)
		error(0);
	else
	{
		get_map_size(argv[1], &size);
		if ((size.x * 32 > MAX_WIDTH) || (size.x * 32 > MAX_WIDTH))
			error(3);
		map = read_map(argv[1], size);
		if (!is_valid_map(map, size))
			error(2);
		else
		{
			init_game(size, map);
		}
	}
	return (0);
}
