/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:09:45 by tquence           #+#    #+#             */
/*   Updated: 2019/04/22 18:06:15 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strrchr(const char *s, int c)
{
	unsigned char	*a;
	unsigned char	c1;

	a = 0;
	c1 = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == c1)
			a = (unsigned char *)s;
		s++;
	}
	if (c1 == 0)
		return ((char *)s);
	return ((char *)a);
}
