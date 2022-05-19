/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 06:58:11 by sifreita          #+#    #+#             */
/*   Updated: 2021/11/26 06:58:12 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (c);
		i++;
	}
	return (0);
}

int	ft_numlen(unsigned long long int n, int base)
{
	int	t;

	if (n == 0)
		return (1);
	t = 0;
	while (n > 0)
	{
		n = n / base;
		t++;
	}
	return (t);
}

void	ft_printf_num(unsigned long int n, char *base)
{
	unsigned long int	l;

	l = ft_strlen(base);
	if (n >= l)
		ft_printf_num(n / l, base);
	write (1, &base[n % l], 1);
}
