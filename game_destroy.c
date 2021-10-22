/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:47:11 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/22 10:26:06 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	end_game(t_program *mlx)
{
	destroy_mlx(mlx);
	exit(0);
}

int	mouse_hook(t_program *mlx)
{
	destroy_mlx(mlx);
	exit(0);
	return (0);
}
