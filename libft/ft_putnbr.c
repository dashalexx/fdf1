/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:58:54 by tquence           #+#    #+#             */
/*   Updated: 2019/04/29 18:27:45 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void		if_neg(int n)
{
	if (n < 0)
		write(1, "-", 1);
}

void			ft_putnbr(int n)
{
	long int	ost;
	long int	k;
	long int	nb;

	nb = (long int)n;
	if (nb == 0)
		write(1, "0", 1);
	else
	{
		if_neg(nb);
		if (nb < 0)
			nb *= -1;
		ost = nb;
		k = razryad(nb);
		while (ost >= 0 && k != 1)
		{
			nb = ost;
			k /= 10;
			ost = ost % k;
			nb /= k;
			ft_putchar('0' + nb);
		}
	}
}
