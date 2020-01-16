/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:39:05 by tquence           #+#    #+#             */
/*   Updated: 2019/04/29 19:04:03 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static unsigned int	count_let(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	while (*s != c && *s != 0)
	{
		i++;
		s++;
	}
	return (i);
}

static unsigned int	count_w(char const *s, char c)
{
	unsigned int	k;

	k = 0;
	if (s)
	{
		while (*s != '\0')
		{
			if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
				k++;
			s++;
		}
		return (k);
	}
	return (0);
}

static char			**ft_split(char const *s, char c)
{
	unsigned int	wrd_i;
	unsigned int	sym_i;
	unsigned int	wrd_num;
	unsigned int	str_i;
	char			**m;

	wrd_i = 0;
	str_i = 0;
	wrd_num = count_w(s, c);
	if (!(m = (char **)malloc(sizeof(m) * (wrd_num + 1))))
		return (0);
	while (wrd_i < wrd_num)
	{
		while (*(s + str_i) == c)
			++str_i;
		if (!(m[wrd_i] = (char *)malloc(sizeof(m[wrd_i]) *
						(count_let(s + str_i, c) + 1))))
			return (0);
		sym_i = 0;
		while (s[str_i] != c && s[str_i] != 0)
			m[wrd_i][sym_i++] = s[str_i++];
		m[wrd_i++][sym_i] = 0;
	}
	m[wrd_i] = 0;
	return (m);
}

char				**ft_strsplit(char const *s, char c)
{
	if (s)
		return (ft_split(s, c));
	return (0);
}
