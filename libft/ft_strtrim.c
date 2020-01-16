/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:00:48 by tquence           #+#    #+#             */
/*   Updated: 2019/04/26 20:15:03 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			only_space(char const *s)
{
	if (s)
	{
		while (*s != 0)
		{
			if (*s != '\t' && *s != '\n' && *s != ' ')
				return (1);
			s++;
		}
	}
	return (0);
}

static int			start(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static int			end_s(const char *s)
{
	unsigned int	end;

	end = ft_strlen(s);
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n' || s[end] == 0)
		end--;
	return (end);
}

char				*ft_strtrim(char const *s)
{
	char			*c;
	unsigned int	i;
	unsigned int	end;
	unsigned int	k;

	k = 0;
	if (only_space(s) == 0)
	{
		c = (char *)malloc(sizeof(*c));
		*c = 0;
		return (c);
	}
	if (s && only_space(s) == 1)
	{
		i = start(s);
		end = end_s(s);
		if (!(c = (char *)malloc(sizeof(*c) * (end - i + 2))))
			return (0);
		c[end - i + 1] = 0;
		while (i <= end)
			c[k++] = (char)s[i++];
		return (c);
	}
	return (0);
}
