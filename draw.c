/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:13:01 by tquence           #+#    #+#             */
/*   Updated: 2019/12/11 19:13:02 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void		iso(int *x, int *y, int z)
{
	int			previous_x;
	int			previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.46373398);
	*y = -z + (previous_x + previous_y) * sin(0.46373398);
}

void			drawline(t_koord p1, t_koord p2, t_fdf *fdf)
{
	t_bresenh	s;

	s.deltax = ft_abs(p2.x - p1.x);
	s.deltay = ft_abs(p2.y - p1.y);
	s.signx = p1.x < p2.x ? 1 : -1;
	s.signy = p1.y < p2.y ? 1 : -1;
	s.error = s.deltax - s.deltay;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		mlx_pixel_put(fdf->p, fdf->wind, p1.x, p1.y, 0xFFFFFF);
		s.error2 = s.error * 2;
		if (s.error2 > -s.deltay)
		{
			s.error -= s.deltay;
			p1.x += s.signx;
		}
		if (s.error2 < s.deltax)
		{
			s.error += s.deltax;
			p1.y += s.signy;
		}
	}
}

void			start_koord(t_fdf *f)
{
	f->start_x = 1000 - f->koef * (f->k / 2);
	f->start_y = 500 - f->koef * (f->n / 2);
}

t_koord			get_koord(int x, int y, int z, t_fdf *f)
{
	t_koord		p;

	p.x = f->start_x + f->koef * x;
	p.y = f->start_y + f->koef * y;
	if (f->projection == 1)
	{
		iso(&p.x, &p.y, z * f->zoom);
		p.x += 300;
		p.y -= 100;
	}
	return (p);
}

void			lines(t_fdf *fdf, int **map)
{
	int			j;
	t_koord		p1;
	t_koord		p2;
	int			i;

	i = 0;
	while (i < fdf->n)
	{
		j = 0;
		p1 = get_koord(0, i, **map, fdf);
		while (j < fdf->k)
		{
			p2 = get_koord(j, i, map[i][j], fdf);
			drawline(p1, p2, fdf);
			if (i > 0)
				drawline(get_koord(j, i - 1, map[i - 1][j], fdf), p2, fdf);
			p1 = p2;
			j++;
		}
		i++;
	}
}
