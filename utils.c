/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:47:11 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/27 11:02:39 by crisfern         ###   ########.fr       */
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
