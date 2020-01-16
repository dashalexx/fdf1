/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:19:13 by tquence           #+#    #+#             */
/*   Updated: 2019/04/24 19:36:05 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*p;

	if (!(p = malloc((size))))
		return (0);
	ft_bzero(p, size);
	return (p);
}
