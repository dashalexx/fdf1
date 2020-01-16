/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:29:42 by tquence           #+#    #+#             */
/*   Updated: 2019/04/12 16:07:58 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int						ft_strcmp(const char *s1, const char *s2)
{
	int					r;
	const unsigned char	*c1;
	const unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (*c1 == '\0')
		return (0 - *c2);
	while (*c1 != '\0')
	{
		if (*c1 == *c2)
		{
			c1++;
			c2++;
		}
		else
		{
			r = *c1 - *c2;
			return (r);
		}
	}
	if (*c1 == '\0')
		return (0 - *c2);
	return (0);
}
