/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:41:29 by tquence           #+#    #+#             */
/*   Updated: 2019/04/08 20:23:05 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		++i;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = 0;
	while (j < i)
	{
		str[j] = s1[j];
		++j;
	}
	return (str);
}
