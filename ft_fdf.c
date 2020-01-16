/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 03:37:44 by tquence           #+#    #+#             */
/*   Updated: 2020/01/16 03:37:45 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		init_struct(t_fdf *fdf, char **map)
{
	fdf->p = mlx_init();
	fdf->wind = mlx_new_window(fdf->p, 2000, 1000, "fdf");
	fdf->n = count_str(map);
	fdf->map = scan_map(map, fdf->k, fdf->n);
	fdf->koef = count_koef(fdf->k);
	start_koord(fdf);
	fdf->zoom = 2;
	fdf->move_x = 0;
	fdf->move_y = 0;
	fdf->projection = 1;
}

int			count_koef(int k)
{
	int		koef;

	koef = 800 / k;
	return (koef);
}

int			events(int key, void *param)
{
	t_fdf	*fdf;

	fdf = ((t_fdf *)param);
	if (key == EXIT_CODE)
		exit(0);
	if (key == PLUS)
		fdf->zoom += 2;
	if (key == MINUS)
		fdf->zoom -= 2;
	if (key == RIGHT)
		fdf->start_x += 4;
	if (key == LEFT)
		fdf->start_x -= 4;
	if (key == DOWN)
		fdf->start_y += 4;
	if (key == UP)
		fdf->start_y -= 4;
	if (key == 49)
		fdf->projection = 1;
	if (key == 36)
		fdf->projection = 0;
	mlx_clear_window(fdf->p, fdf->wind);
	lines(fdf, fdf->map);
	return (0);
}

int			count_symb(char *map)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	if (map[0] != ' ')
		k++;
	while (map[i] != 0)
	{
		if ((map[i] == ' ') && ((map[i + 1] != ' ' && map[i + 1])))
			k++;
		i++;
	}
	return (k);
}

int			ft_abs(int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}
