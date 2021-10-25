/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:47:11 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/25 16:26:26 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int nb)
{
	unsigned int	nbr;
	char			z;

	if (nb < 0)
	{
		z = '-';
		write(1, &z, 1);
		nb = nb * (-1);
	}
	nbr = (unsigned int) nb;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		z = '0' + (nbr % 10);
		write(1, &z, 1);
	}
	else
	{
		z = '0' + nbr;
		write(1, &z, 1);
	}
}

static int	get_digits(int n)
{
	int	digits;

	digits = 1;
	while (n > 9)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int		dig;
	char	*str;

	dig = get_digits(n) + 1;
	str = ft_calloc(dig + 1, 1);
	if (str)
	{
		while (--dig > 0)
		{
			str[dig - 1] = '0' + n % 10;
			n /= 10;
		}
	}
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	if (s)
	{
		while (*s++)
			n++;
	}
	return (n);
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
