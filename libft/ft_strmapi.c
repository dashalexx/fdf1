/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:56:54 by tquence           #+#    #+#             */
/*   Updated: 2019/04/22 21:06:49 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	k;
	char			*c;

	if (s)
	{
		k = 0;
		if (!(c = (char *)malloc(sizeof(*c) + ft_strlen(s))))
			return (0);
		while (s[k] != '\0')
		{
			c[k] = f(k, (char)s[k]);
			k++;
		}
		c[k] = '\0';
		return (c);
	}
	return (0);
}
