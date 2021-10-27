/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:21:26 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/27 10:42:04 by crisfern         ###   ########.fr       */
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
		write(1, "Error\nNo argument for map", 25);
	else if (i == 1)
		write(1, "Error\nToo many arguments", 24);
	else if (i == 2)
		write(1, "Error\nCan't open file", 21);
	else if (i == 3)
		write(1, "Error\nMap not rectangular", 25);
	else if (i == 4)
		write(1, "Error\nMap not valid", 19);
	else if (i == 5)
		write(1, "Error\nExtension not valid", 25);
	else if (i == 6)
		write(1, "Error\nCouldn't read map", 23);
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

static int	check_extension(char *str)
{
	char	*aux;

	aux = str;
	if (aux)
	{
		while (*aux)
		{
			if ((*aux == '.') && (*(aux + 1)))
			{
				if ((*(aux + 1) == 'b') && (*(aux + 2)))
					if ((*(aux + 2) == 'e') && (*(aux + 3)))
						if ((*(aux + 3) == 'r') && !(*(aux + 4)))
							return (1);
			}
			aux++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_program	mlx;

	atexit(leaks);
	if (argc < 2)
		error(0);
	else if (argc > 2)
		error(1);
	else if (!check_extension(argv[1]))
		error(5);
	init_struct_map(&map);
	init_struct_prog(&mlx);
	get_map_size(argv[1], &map);
	mlx.map = read_map(argv[1], &map);
	if (mlx.map)
	{
		if (!is_valid_map(&mlx, &map))
			error(4);
		else
			init_game(&map, &mlx);
	}
	else
		error(6);
	return (0);
}
