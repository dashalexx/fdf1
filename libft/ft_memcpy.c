/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:26:36 by tquence           #+#    #+#             */
/*   Updated: 2019/04/12 15:20:36 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			k;
	unsigned char	*s1;
	unsigned char	*s2;

	k = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	while (k < n)
	{
		*s1 = *s2;
		k++;
		s1++;
		s2++;
	}
	return (dst);
}
