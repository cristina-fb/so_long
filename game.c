/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:47:11 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/21 15:47:05 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_images(t_program *mlx)
{
	int	w;
	int	h;

	mlx->grass = mlx_xpm_file_to_image(mlx->ptr, "./spr/grass.xpm", &w, &h);
	mlx->water = mlx_xpm_file_to_image(mlx->ptr, "./spr/water.xpm", &w, &h);
	mlx->cat_f[0] = mlx_xpm_file_to_image(mlx->ptr, "./spr/gfr.xpm", &w, &h);
	mlx->cat_f[1] = mlx_xpm_file_to_image(mlx->ptr, "./spr/gfl.xpm", &w, &h);
	mlx->cat_b[0] = mlx_xpm_file_to_image(mlx->ptr, "./spr/gbr.xpm", &w, &h);
	mlx->cat_b[1] = mlx_xpm_file_to_image(mlx->ptr, "./spr/gbl.xpm", &w, &h);
	mlx->cat_l[0] = mlx_xpm_file_to_image(mlx->ptr, "./spr/glr.xpm", &w, &h);
	mlx->cat_l[1] = mlx_xpm_file_to_image(mlx->ptr, "./spr/gll.xpm", &w, &h);
	mlx->cat_r[0] = mlx_xpm_file_to_image(mlx->ptr, "./spr/grr.xpm", &w, &h);
	mlx->cat_r[1] = mlx_xpm_file_to_image(mlx->ptr, "./spr/grl.xpm", &w, &h);
	mlx->mush = mlx_xpm_file_to_image(mlx->ptr, "./spr/mush.xpm", &w, &h);
	mlx->hole = mlx_xpm_file_to_image(mlx->ptr, "./spr/hole.xpm", &w, &h);
}

void	destroy_mlx(t_program *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->wdw);
	mlx_destroy_image(mlx->ptr, mlx->grass);
	mlx_destroy_image(mlx->ptr, mlx->cat_f[0]);
	mlx_destroy_image(mlx->ptr, mlx->cat_f[1]);
	mlx_destroy_image(mlx->ptr, mlx->cat_b[0]);
	mlx_destroy_image(mlx->ptr, mlx->cat_b[1]);
	mlx_destroy_image(mlx->ptr, mlx->cat_l[0]);
	mlx_destroy_image(mlx->ptr, mlx->cat_l[1]);
	mlx_destroy_image(mlx->ptr, mlx->cat_r[0]);
	mlx_destroy_image(mlx->ptr, mlx->cat_r[1]);
}

void	print_map(t_program *mlx, t_map size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (mlx->map[i][j] == '1')
				mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->grass, 32 * j, 32 * i);
			else
			{
				mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->water, 32 * j, 32 * i);
				if (mlx->map[i][j] == 'P')
				{
					mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->cat_f[1], 32 * j, 32 * i);
					mlx->x = j;
					mlx->y = i;
				}
				if (mlx->map[i][j] == 'C')
				{
					mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->mush, 32 * j, 32 * i);
					mlx->obj++;
				}
				if (mlx->map[i][j] == 'E')
					mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->hole, 32 * j, 32 * i);
			}
			j++;
		}
		i++;
	}
}

int	mouse_hook(t_program *mlx)
{
	destroy_mlx(mlx);
	exit(0);
	return (0);
}

void	init_game(t_map size, char **map)
{
	t_program	mlx;

	mlx.map = map;
	mlx.cat_mov = 0;
	mlx.obj = 0;
	mlx.ptr = mlx_init();
	mlx.wdw = mlx_new_window(mlx.ptr, 32 * size.x, 32 * size.y, "so_long");
	create_images(&mlx);
	print_map(&mlx, size);
	mlx_hook(mlx.wdw, 17, 1L << 1, mouse_hook, &mlx);
	mlx_key_hook(mlx.wdw, key_hook, &mlx);
	mlx_loop(mlx.ptr);
}
