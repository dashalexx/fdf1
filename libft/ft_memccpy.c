/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:37:51 by tquence           #+#    #+#             */
/*   Updated: 2019/04/22 17:45:31 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			k;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	c1;

	k = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	c1 = (unsigned char)c;
	while (k < n)
	{
		s1[k] = s2[k];
		if (s1[k] == c1)
		{
			k++;
			return ((void *)(&dst[k]));
		}
		k++;
	}
	return (0);
}
