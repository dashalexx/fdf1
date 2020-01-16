/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:47:41 by tquence           #+#    #+#             */
/*   Updated: 2019/04/17 19:39:50 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	k;
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	p;

	i = 0;
	j = 0;
	x = size;
	while (dst[i] != 0 && x != 0)
	{
		i++;
		--x;
	}
	k = ft_strlen(src);
	x = size - i;
	if (x == 0)
		return (size + k);
	p = i;
	while (src[j] != 0 && (x-- > 1))
		dst[p++] = src[j++];
	dst[p] = 0;
	return (i + k);
}
