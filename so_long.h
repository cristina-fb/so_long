/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:19:54 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/21 15:46:33 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080

typedef struct s_program
{
	void	*ptr;
	void	*wdw;
	void	*grass;
	void	*water;
	void	*mush;
	void	*hole;
	void	*cat_f[2];
	void	*cat_b[2];
	void	*cat_l[2];
	void	*cat_r[2];
	int		cat_mov;
	int		x;
	int		y;
	int		obj;
	char	**map;
}	t_program;

typedef struct s_map
{
	int		x;
	int		y;
}	t_map;

void	error(int i);
void	get_map_size(char *file, t_map *size);
void	init_game(t_map size, char **map);
void	destroy_mlx(t_program *mlx);
void	create_images(t_program *mlx);
void	destroy_mlx(t_program *mlx);
void	print_map(t_program *mlx, t_map size);
void	init_game(t_map size, char **map);

int		is_valid_map(char **map, t_map size);
int		key_hook(int keycode, t_program *mlx);
int		mouse_hook(t_program *mlx);

char	**read_map(char *file, t_map size);
#endif
