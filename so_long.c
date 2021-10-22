/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:21:26 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/22 16:42:31 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks so_long");
}

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

void	init_game(t_map size, char **map)
{
	t_program	mlx;

	mlx.map = map;
	mlx.cat_mov = 0;
	mlx.obj = 0;
	mlx.n_mov = 0;
	mlx.ptr = mlx_init();
	mlx.wdw = mlx_new_window(mlx.ptr, 64 * size.x, 64 * size.y, "so_long");
	create_images(&mlx);
	print_map(&mlx, size);
	mlx_hook(mlx.wdw, 17, 1L << 1, mouse_hook, &mlx);
	mlx_key_hook(mlx.wdw, key_hook, &mlx);
	mlx_string_put(mlx.ptr, mlx.wdw, 64, 32, 0, "Number of movements:");
	mlx_loop(mlx.ptr);
}

int	main(int argc, char **argv)
{
	t_map	size;
	char	**map;

	atexit(leaks);
	if (argc != 2)
		error(0);
	else
	{
		get_map_size(argv[1], &size);
		if ((size.x * 64 > MAX_WIDTH) || (size.x * 64 > MAX_WIDTH))
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
