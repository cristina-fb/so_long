/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:47:11 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/22 16:48:46 by crisfern         ###   ########.fr       */
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
		if (mlx->map[i][j] == 'C')
		{
			mlx_put_image_to_window(mlx->ptr, mlx->wdw,
				mlx->mush, 64 * j, 64 * i);
			mlx->obj++;
		}
		if (mlx->map[i][j] == 'E')
			mlx_put_image_to_window(mlx->ptr, mlx->wdw,
				mlx->hole, 64 * j, 64 * i);
	}
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
			print_map_aux(mlx, i, j);
			j++;
		}
		i++;
	}
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
