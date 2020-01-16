/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:17:03 by tquence           #+#    #+#             */
/*   Updated: 2019/12/11 19:17:04 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include <math.h>

# define DEF_MAP_SIZE 20
# define EXIT_CODE	53
# define PLUS  		69
# define MINUS		78
# define RIGHT 		2
# define LEFT  		0
# define UP    		13
# define DOWN  		1

typedef struct	s_fdf
{
	void		*p;
	void		*wind;
	int			k;
	int			n;
	int			koef;
	int			**map;
	int			start_x;
	int			start_y;
	int			zoom;
	int			move_x;
	int			move_y;
	int			projection;
}				t_fdf;

typedef struct	s_koord
{
	int			x;
	int			y;
	int			z;
}				t_koord;

typedef struct	s_bresenh
{
	int			deltax;
	int			deltay;
	int			signx;
	int			signy;
	int			error;
	int			error2;
}				t_bresenh;

int				events(int key, void *param);
void			init_struct(t_fdf *fdf, char **map);
void			start_koord(t_fdf *f);
int				*write_numbers(char *map, int k);
int				**scan_map(char **map, int k, int n);
void			*ft_realloc(void *buf, size_t old, size_t new);
int				count_symb(char *map);
int				count_str(char **map);
char			**draw1(const int fd, int n);
char			**read_map(char *fname);
int				ft_abs(int a);
void			drawline(t_koord p1, t_koord p2, t_fdf *fdf);
int				count_koef(int k);
void			lines(t_fdf *fdf, int **map);
int				valid(char **map, t_fdf *fdf);
int 			valid_int_map(char **map, int k);

#endif
