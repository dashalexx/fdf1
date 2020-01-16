/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:12:52 by tquence           #+#    #+#             */
/*   Updated: 2019/04/24 21:21:48 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (0);
	if (content == NULL)
	{
		p->content = 0;
		p->content_size = 0;
		p->next = NULL;
		return (p);
	}
	if (!(p->content = (void *)malloc(content_size)))
		return (0);
	ft_memcpy(p->content, content, content_size);
	p->content_size = content_size;
	p->next = 0;
	return (p);
}
