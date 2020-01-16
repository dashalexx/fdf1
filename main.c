/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 03:37:53 by tquence           #+#    #+#             */
/*   Updated: 2020/01/16 03:37:54 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int			count_str(char **map)
{
	int		n;

	n = 0;
	while (*map != 0)
	{
		map++;
		n++;
	}
	return (n);
}

int			*write_numbers(char *map, int k)
{
	int		*m;
	int		i;

	i = 0;
	if (!(m = (int *)malloc(sizeof(int) * k)))
		exit(1);
	while (*map)
	{
		if (((*map >= 48) && (*map <= 57)) || (*map == '-'))
		{
			m[i] = ft_atoi(map);
			while (((*map >= 48) && (*map <= 57)) || (*map == '-'))
				map++;
			i++;
		}
		else if (*map == ' ')
			map++;
	}
	return (m);
}

int			**scan_map(char **map, int k, int n)
{
	int		**m;
	int		i;

	i = 0;
	if (!(m = (int **)ft_memalloc(sizeof(int *) * (n + 1))))
		exit(1);
	while (map[i])
	{
		m[i] = write_numbers(map[i], k);
		i++;
	}
	return (m);
}

char		**read_map(char *fname)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;
	int		size;

	size = DEF_MAP_SIZE;
	if ((fd = open(fname, O_RDONLY)) < 0)
		return (NULL);
	i = 0;
	if (!(map = (char **)ft_memalloc(sizeof(char *) * size)))
		return (NULL);
	while ((get_next_line(fd, &line)) != 0)
	{
		if (i == size - 2)
		{
			size *= 2;
			map = ft_realloc(map, (sizeof(char *) * size) / 2,
					sizeof(char *) * size);
		}
		map[i++] = line;
	}
	map[i] = 0;
	close(fd);
	return (map);
}

int			main(int argc, char **argv)
{
	t_fdf	fdf;
	char	**m;

	if (argc != 2 || !(m = read_map(argv[1])))
	{
		ft_putstr("error\n");
		exit(1);
	}
	if (valid(m, &fdf))
	{
		ft_putstr("error\n");
		exit(1);
	}
	init_struct(&fdf, m);
	lines(&fdf, fdf.map);
	mlx_hook(fdf.wind, 2, 0, &events, (void *)&fdf);
	mlx_loop(fdf.p);
	return (0);
}
