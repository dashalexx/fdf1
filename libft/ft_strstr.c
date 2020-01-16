/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:31:07 by tquence           #+#    #+#             */
/*   Updated: 2019/04/24 20:22:28 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *a;
	char *b;

	a = 0;
	b = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack != 0)
	{
		b = (char *)haystack;
		a = (char *)needle;
		while (*haystack == *a && *a != 0)
		{
			++haystack;
			++a;
			if (*a == '\0')
				return (b);
		}
		haystack = b;
		++haystack;
	}
	return (0);
}
