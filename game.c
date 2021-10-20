/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:47:11 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/20 15:02:53 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_game(t_map map_size, char **map)
{
    t_program   mlx;
    int     width;
    int     height;
    int a;

    mlx.ptr = mlx_init();
    mlx.wdw = mlx_new_window(mlx.ptr, 32*map_size.x, 32*map_size.y, "so_long");

    mlx.img = mlx_xpm_file_to_image(mlx.ptr, "./sprites/front_right.xpm", &width, &height);
    mlx_put_image_to_window(mlx.ptr, mlx.wdw, mlx.img, 0, 0);

    //mlx_hook(mlx.wdw, 17, 1L<<1, mouse_hook, &mlx);
    //mlx_key_hook(mlx.wdw, key_hook, &mlx);
    mlx_loop(mlx.ptr);
    a = map[0][0];
}