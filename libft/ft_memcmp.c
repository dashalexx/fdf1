/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:45:30 by tquence           #+#    #+#             */
/*   Updated: 2019/04/12 15:25:20 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			k;

	k = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (k < n)
	{
		if (*a == *b)
		{
			a++;
			b++;
			k++;
		}
		else
			return (*a - *b);
	}
	return (0);
}
