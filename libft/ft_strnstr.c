/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:33:17 by tquence           #+#    #+#             */
/*   Updated: 2019/04/29 18:52:52 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		k;
	size_t		i;
	size_t		d;
	size_t		a;

	if (*needle == 0)
		return ((char *)haystack);
	k = -1;
	while (haystack[++k] != '\0' && len != 0)
	{
		i = 0;
		d = k;
		a = len;
		while (haystack[k++] == needle[i] && len-- != 0 && needle[i] != 0)
			++i;
		if (needle[i] == '\0')
			return ((char *)&haystack[d]);
		k = d;
		len = a - 1;
		if (haystack[k] == 0)
			return (0);
	}
	return (0);
}
