 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:42:41 by tquence           #+#    #+#             */
/*   Updated: 2019/05/06 18:42:50 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		find_n(char **str, char **line)
{
	char		*p;
	int			i;

	if (!*str)
		return (0);
	p = *str;
	i = 0;
	while (p[i] != '\n')
	{
		if (p[i] == 0)
			return (0);
		i++;
	}
	p[i] = 0;
	*str = ft_strdup(&p[i + 1]);
	*line = ft_strdup(p);
	free(p);
	p = 0;
	return (1);
}

static int		readline(int fd, char **str, char *buf, char **line)
{
	char		*c;

	while (read(fd, buf, BUFF_SIZE) != 0)
	{
		if (!*str)
			*str = ft_strdup(buf);
		else
		{
			c = *str;
			*str = ft_strjoin(*str, buf);
			free(c);
		}
		if (*str && find_n(str, line) == 1)
			return (1);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*str[MAX_FD];

	if (BUFF_SIZE <= 0)
		return (-1);
	if (read(fd, buf, 0) < 0 || fd < 0)
		return (-1);
	if (str[fd] && find_n(&str[fd], line) == 1)
		return (1);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (readline(fd, &str[fd], buf, line) > 0)
		return (1);
	if (str[fd] && str[fd][0] != 0 && find_n(&str[fd], line) == 0)
	{
		*line = str[fd];
		str[fd] = 0;
		return (1);
	}
	return (0);
}
