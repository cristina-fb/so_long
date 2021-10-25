/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:21:26 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/25 16:08:56 by crisfern         ###   ########.fr       */
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

static void	init_struct_map(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->pos = 0;
	map->col = 0;
	map->exit = 0;
}

static void	init_struct_prog(t_program *mlx)
{
	mlx->ptr = NULL;
	mlx->wdw = NULL;
	mlx->grass = NULL;
	mlx->water = NULL;
	mlx->mush = NULL;
	mlx->hole = NULL;
	mlx->cat_f[0] = NULL;
	mlx->cat_f[1] = NULL;
	mlx->cat_b[0] = NULL;
	mlx->cat_b[1] = NULL;
	mlx->cat_l[0] = NULL;
	mlx->cat_l[1] = NULL;
	mlx->cat_r[0] = NULL;
	mlx->cat_r[1] = NULL;
	mlx->cat_mov = 0;
	mlx->x = 0;
	mlx->y = 0;
	mlx->obj = 0;
	mlx->n_mov = 0;
	mlx->map = NULL;
}

static void	init_game(t_map *map, t_program *mlx)
{
	mlx->ptr = mlx_init();
	mlx->wdw = mlx_new_window(mlx->ptr, 64 * map->x, 64 * map->y, "so_long");
	create_images(mlx);
	print_map(mlx, map);
	mlx_hook(mlx->wdw, 17, 1L << 1, mouse_hook, mlx);
	mlx_key_hook(mlx->wdw, key_hook, mlx);
	mlx_string_put(mlx->ptr, mlx->wdw, 64, 32, 0, "Number of movements:");
	mlx_loop(mlx->ptr);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_program	mlx;

	atexit(leaks);
	if (argc != 2)
		error(0);
	else
	{
		init_struct_map(&map);
		init_struct_prog(&mlx);
		get_map_size(argv[1], &map);
		mlx.map = read_map(argv[1], &map);
		if (mlx.map)
		{
			if (!is_valid_map(&mlx, &map))
				error(2);
			else
				init_game(&map, &mlx);
		}
	}
	return (0);
}
