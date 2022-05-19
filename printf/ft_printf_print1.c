/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fncts1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:52:37 by sifreita          #+#    #+#             */
/*   Updated: 2021/11/26 02:52:38 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printf_s(char *c)
{
	int	i;

	i = 0;
	if (!c)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	return (ft_strlen(c));
}

int	ft_printf_d(int n)
{
	int	t;

	t = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		t = t + 1;
	}
	ft_printf_num(n, "0123456789");
	t = t + ft_numlen(n, 10);
	return (t);
}
