/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:38:22 by tquence           #+#    #+#             */
/*   Updated: 2019/04/22 21:00:23 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*s;
	size_t	k;

	k = 0;
	if (!(s = (char *)malloc(sizeof(*s) * (size + 1))))
		return (0);
	while (k != size + 1)
	{
		s[k] = 0;
		k++;
	}
	k = 0;
	while (k != size + 1)
	{
		if (s[k] == '\0')
			k++;
		else
			return (NULL);
	}
	return (s);
}
