/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:19:54 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/25 16:06:43 by crisfern         ###   ########.fr       */
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
	int		n_mov;
	char	**map;
}	t_program;

typedef struct s_map
{
	int		x;
	int		y;
	int		pos;
	int		col;
	int		exit;
}	t_map;

void	error(int i);
void	get_map_size(char *file, t_map *map);
void	create_images(t_program *mlx);
void	print_map(t_program *mlx, t_map *map);
void	print_mov(t_program *mlx);
void	end_game(t_program *mlx);
void	ft_putnbr(int nb);

int		is_valid_map(t_program *mlx, t_map *map);
int		key_hook(int keycode, t_program *mlx);
int		mouse_hook(t_program *mlx);
size_t	ft_strlen(const char *s);

char	*ft_itoa(int n);
char	**read_map(char *file, t_map *map);
#endif
