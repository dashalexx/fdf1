/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:26:31 by tquence           #+#    #+#             */
/*   Updated: 2019/04/25 20:28:14 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_atoi(const char *str)
{
	long int	a;
	long int	zn;
	long int	prev;

	a = 0;
	zn = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' && *(str + 1) != '-' && *(str + 1) != '+')
	{
		zn *= -1;
		str++;
	}
	if (*str == '+' && *(str + 1) != '-' && *(str + 1) != '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		prev = a;
		a = (a * 10) + (*str - 48);
		str++;
		if (prev > a)
			return (zn > 0 ? -1 : 0);
	}
	return (a * zn);
}
