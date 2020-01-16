/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:19:17 by tquence           #+#    #+#             */
/*   Updated: 2019/04/24 19:38:40 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			k;
	char			*c;

	if (s)
	{
		i = 0;
		k = 0;
		while (i++ != start)
			++s;
		if (!(c = (char *)ft_memalloc(sizeof(*c) * (len + 1))))
			return (0);
		c[len] = 0;
		while (k != len)
			c[k++] = *s++;
		return (c);
	}
	return (0);
}
