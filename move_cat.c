/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:47:11 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/21 13:46:10 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_program *mlx)
{
	if (mlx->map[mlx->y - 1][mlx->x] != '1')
	{
		mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->water,
			32 * mlx->x, 32 * mlx->y);
		mlx->y--;
		mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->cat_b[mlx->cat_mov],
			32 * mlx->x, 32 * mlx->y);
		if (mlx->cat_mov)
			mlx->cat_mov = 0;
		else
			mlx->cat_mov = 1;
	}
}

static void	move_down(t_program *mlx)
{
	if (mlx->map[mlx->y + 1][mlx->x] != '1')
	{
		mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->water,
			32 * mlx->x, 32 * mlx->y);
		mlx->y++;
		mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->cat_f[mlx->cat_mov],
			32 * mlx->x, 32 * mlx->y);
		if (mlx->cat_mov)
			mlx->cat_mov = 0;
		else
			mlx->cat_mov = 1;
	}
}

static void	move_left(t_program *mlx)
{
	if (mlx->map[mlx->y][mlx->x - 1] != '1')
	{
		mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->water,
			32 * mlx->x, 32 * mlx->y);
		mlx->x--;
		mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->cat_l[mlx->cat_mov],
			32 * mlx->x, 32 * mlx->y);
		if (mlx->cat_mov)
			mlx->cat_mov = 0;
		else
			mlx->cat_mov = 1;
	}
}

static void	move_right(t_program *mlx)
{
	if (mlx->map[mlx->y][mlx->x + 1] != '1')
	{
		mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->water,
			32 * mlx->x, 32 * mlx->y);
		mlx->x++;
		mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->cat_r[mlx->cat_mov],
			32 * mlx->x, 32 * mlx->y);
		if (mlx->cat_mov)
			mlx->cat_mov = 0;
		else
			mlx->cat_mov = 1;
	}
}

int	key_hook(int keycode, t_program *mlx)
{
	if (keycode == 0)
		move_left(mlx);
	else if (keycode == 1)
		move_down(mlx);
	else if (keycode == 2)
		move_right(mlx);
	else if (keycode == 13)
		move_up(mlx);
	if (keycode == 53)
	{
		destroy_mlx(mlx);
		exit(0);
	}
	return (0);
}
