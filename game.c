/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:47:11 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/27 10:23:57 by crisfern         ###   ########.fr       */
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

void	end_game(t_program *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->wdw);
	mlx_destroy_image(mlx->ptr, mlx->grass);
	mlx_destroy_image(mlx->ptr, mlx->water);
	mlx_destroy_image(mlx->ptr, mlx->cat_f[0]);
	mlx_destroy_image(mlx->ptr, mlx->cat_f[1]);
	mlx_destroy_image(mlx->ptr, mlx->cat_b[0]);
	mlx_destroy_image(mlx->ptr, mlx->cat_b[1]);
	mlx_destroy_image(mlx->ptr, mlx->cat_l[0]);
	mlx_destroy_image(mlx->ptr, mlx->cat_l[1]);
	mlx_destroy_image(mlx->ptr, mlx->cat_r[0]);
	mlx_destroy_image(mlx->ptr, mlx->cat_r[1]);
	mlx_destroy_image(mlx->ptr, mlx->mush);
	mlx_destroy_image(mlx->ptr, mlx->hole);
	exit(0);
}

int	mouse_hook(t_program *mlx)
{
	end_game(mlx);
	return (0);
}

void	print_mov(t_program *mlx)
{
	char	*num;

	mlx->n_mov++;
	num = ft_itoa(mlx->n_mov);
	mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->grass, 256, 0);
	mlx_string_put(mlx->ptr, mlx->wdw, 260, 32, 0, num);
	free(num);
	write(1, "Number of movements: ", 21);
	ft_putnbr(mlx->n_mov);
	write(1, "\n", 1);
}

void	init_game(t_map *map, t_program *mlx)
{
	mlx->ptr = mlx_init();
	mlx->wdw = mlx_new_window(mlx->ptr, 64 * map->x, 64 * map->y, "so_long");
	create_images(mlx);
	print_map(mlx, map);
	mlx_hook(mlx->wdw, 17, 1L << 1, mouse_hook, mlx);
	mlx_key_hook(mlx->wdw, key_hook, mlx);
	mlx_string_put(mlx->ptr, mlx->wdw, 64, 32, 0, "Number of movements:");
	mlx_string_put(mlx->ptr, mlx->wdw, 260, 32, 0, "0");
	mlx_loop(mlx->ptr);
}
