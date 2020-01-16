/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:09:59 by tquence           #+#    #+#             */
/*   Updated: 2020/01/14 22:10:01 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	*ft_realloc(void *buf, size_t old, size_t new_size)
{
	unsigned char	*new_buf;

	if (!(new_buf = (unsigned char *)ft_memalloc(new_size)))
		exit(1);
	if (buf)
		ft_memcpy(new_buf, buf, old);
	free(buf);
	return (new_buf);
}

int		valid(char **map, t_fdf *fdf)
{
	int			i;
	int			j;

	if (!(*map) || !(**map))
		return (1);
	i = 0;
	fdf->k = count_symb(*map);
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != 0)
		{
			if (((map[i][j] < 48) || (map[i][j] > 57)) &&
				((map[i][j] != '-') && (map[i][j] != ' ')))
				return (1);
			j++;
		}
		i++;
	}
	return (valid_int_map(map, fdf->k));
}

int		valid_int_map(char **map, int k)
{
	int			i;

	i = 0;
	while (map[i] != 0)
	{
		if (count_symb(map[i]) != k)
			return (2);
		i++;
	}
	return (0);
}
