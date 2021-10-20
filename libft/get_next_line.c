/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:43:47 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/20 10:47:10 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int		n_bytes;
	char	*aux;
	char	*str;
	char	a[2];

	str = NULL;
	n_bytes = read(fd, &a, 1);
	a[1] = 0;
	while (n_bytes > 0)
	{
		if (a[0] == '\n')
			break ;
		if (!str)
			str = ft_strdup(a);
		else
		{
			aux = ft_strjoin(str, a);
			free(str);
			str = aux;
		}
		n_bytes = read(fd, &a, 1);
	}
	return (str);
}
