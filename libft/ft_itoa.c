/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:44:16 by tquence           #+#    #+#             */
/*   Updated: 2019/04/29 19:19:45 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int		count_num(long int nb)
{
	long int	n;
	long int	k;

	n = nb;
	k = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		k++;
		n /= 10;
	}
	return (k);
}

static long int	ft_abs(long int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char			*ft_itoa(int n)
{
	char		*c;
	long int	k;
	long int	a;
	long int	nb;

	nb = (long int)n;
	n = 0;
	a = count_num(nb);
	if (nb < 0)
		a = count_num(nb) + 1;
	if (!(c = ft_strnew(a)))
		return (0);
	k = razryad(nb);
	if (nb < 0)
		c[n++] = '-';
	nb = ft_abs(nb);
	a = nb;
	while ((a = a % k) >= 0 && k != 1)
	{
		nb = a;
		k /= 10;
		c[n++] = '0' + (nb / k);
	}
	return (c);
}
