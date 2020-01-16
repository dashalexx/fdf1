/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:42:35 by tquence           #+#    #+#             */
/*   Updated: 2019/12/04 19:42:39 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../minilibx_macos/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "ft_fdf.h"

int    count_symb(const int fd)
{
	int k;
	char buf[2];
	int i;
	char str[500];
	int i1;

	i = 0;
	k = 0;
	ft_bzero(str, 500);
    ft_bzero(buf, 2);
	while (read(fd, buf, 1) != 0)
	{
        if (buf[0] == '\n')
            break ;
        str[i] = buf[0];
        i++;
    }
	i1 = i;
	i = 0;
    if (str[0] != ' ')
        k++;
	while (str[i] != 0)
    {
	    if ((str[i] == ' ') && ((str[i + 1] != ' ') || (str[i + 1] == '\n')))
	        k++;
	    i++;
    }
//	i = 0;
//	while (i != i1)
//    {
//	    free(&str[i]);
//    }
	return (k);
}

char **draw1(const int fd, int n) {
    char **map;
    char *line;
    int i;

    i = 0;
    map = (char **) ft_memalloc(sizeof(char *) * n);
    while ((get_next_line(fd, &line)) != 0)
        map[i++] = line;
    map[i] = 0;
    return (map);
}

int**	karta_save(char **map, int k, int n)
{
    int **m;
    int i;
    int j;
    int p0;
    int p1;

    p0 = 0;
    p1 = 0;
    i = 0;
    j = 0;
    m = (int **)malloc(sizeof(m) * n);
    while (map[p0] != 0)
    {
//        printf("!!!!!!!!!!!!");
        if (j == 0)
            m[i] = (int *)malloc(sizeof(m[i]) * k);
        if (((map[p0][p1] >= 48) && (map[p0][p1] <= 57)) || (map[p0][p1] == '-'))
        {
            m[i][j] = ft_atoi(&map[p0][p1]);
//            printf("%d", m[i][j]);
            while (((map[p0][p1] >= 48) && (map[p0][p1] <= 57)) || (map[p0][p1] == '-'))
                p1++;
            j++;
        }
        else if (map[p0][p1] == ' ')
            p1++;
        if (j == k)
        {
            i++;
            j = 0;
            p1 = 0;
            p0++;
        }
    }
    return (m);
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    int fd;
    int **tmp;
    int i = 0;
    int k;
    int n;
    char **c;
    int j;

    i = 0;
    j = 0;
    fd = open("42.fdf", O_RDONLY);
    k = count_symb(fd);
    close(fd);
//    printf("%d", k);
    fd = open("42.fdf", O_RDONLY);
    n = count_str(fd);
//    printf("%d", n);
    close(fd);
    fd = open("42.fdf", O_RDONLY);
    c = draw1(fd, n);
    close(fd);
    tmp = karta_save(c, k, n);
	while (i < n)
	{
	    j = 0;
	    while (j < k)
        {
            printf("%d ",tmp[i][j]);
            j++;
        }
	    if (j == k)
	        printf("\n");
		i++;
	}
	fd = open("karta", O_RDONLY);
//	while (get_next_line(fd, &c) == 1)
//	{
//		printf("%s\n", c);
//		free(c);
//	}
//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "mlx 42");
//	mlx_pixel_put(mlx_ptr, win_ptr, 400, 400, 0xFFFFFF);
//	drawLine(100, 100, 100, 700);
//	mlx_key_hook(win_ptr, &deal_key, (void *)0);
//	mlx_loop(mlx_ptr);
//	ft_putstr(c);
    return (0);
}
