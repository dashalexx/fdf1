/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:15:39 by tquence           #+#    #+#             */
/*   Updated: 2019/04/26 16:29:58 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*c;

	if (s)
	{
		i = 0;
		if (!(c = (char *)malloc(sizeof(*c) + ft_strlen(s))))
			return (0);
		while (s[i] != '\0')
		{
			c[i] = f(s[i]);
			i++;
		}
		c[i] = '\0';
		return (c);
	}
	return (0);
}
