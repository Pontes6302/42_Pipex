/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 03:35:17 by sifreita          #+#    #+#             */
/*   Updated: 2021/11/22 03:35:20 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	*ft_redirect(char c)
{
	if (c == 'c')
		return (ft_printf_c);
	if (c == 's')
		return (ft_printf_s);
	if (c == 'X')
		return (ft_printf_xm);
	if (c == 'd')
		return (ft_printf_d);
	if (c == 'i')
		return (ft_printf_d);
	if (c == 'u')
		return (ft_printf_u);
	if (c == 'x')
		return (ft_printf_x);
	return (ft_printf_p);
}

int	ft_printf(const char *par, ...)
{
	int		i;
	int		c;
	va_list	ag;

	va_start(ag, par);
	i = 0;
	c = 0;
	while (par[i])
	{
		if (par[i] == '%' && ft_strchr("cspdiuxX", par[++i]))
		{
			c = c + (((int (*)())ft_redirect(par[i++]))(va_arg(ag, void *)));
			continue ;
		}
		write (1, par + i, 1);
		c++;
		i++;
	}
	va_end(ag);
	return (c);
}
