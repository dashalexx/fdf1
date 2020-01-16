/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:30:14 by tquence           #+#    #+#             */
/*   Updated: 2019/04/17 15:29:17 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*m;
	size_t			k;
	unsigned char	c1;

	k = 0;
	c1 = (unsigned char)c;
	m = (unsigned char *)s;
	while (k < n)
	{
		if (m[k] == c1)
			return ((void *)(&s[k]));
		k++;
	}
	return (0);
}
