/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:20:53 by tquence           #+#    #+#             */
/*   Updated: 2019/04/16 23:48:16 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		k;
	char		*s1;
	char		*s2;

	k = 0;
	s1 = (char *)dst;
	s2 = (char *)src;
	if (s2 > s1)
	{
		while (k != len)
		{
			s1[k] = s2[k];
			++k;
		}
	}
	else if (s2 < s1)
	{
		while (len-- != 0)
			s1[len] = s2[len];
	}
	return (dst);
}
