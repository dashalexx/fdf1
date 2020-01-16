/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:11:01 by tquence           #+#    #+#             */
/*   Updated: 2019/04/18 16:35:19 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void		if_neg(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
}

static long int	mmm(long int n)
{
	long int	k;

	k = 1;
	while (n > 0)
	{
		k *= 10;
		n /= 10;
	}
	return (k);
}

void			ft_putnbr_fd(int n, int fd)
{
	long int	ost;
	long int	k;
	long int	nb;

	if (fd >= 0)
	{
		nb = (long int)n;
		if (nb == 0)
			write(fd, "0", 1);
		if_neg(nb, fd);
		if (n < 0)
			nb *= -1;
		ost = nb;
		k = mmm(nb);
		while (ost >= 0 && k != 1)
		{
			nb = ost;
			k /= 10;
			ost = ost % k;
			nb /= k;
			ft_putchar_fd('0' + nb, fd);
		}
	}
}
