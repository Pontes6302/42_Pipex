/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 06:56:16 by sifreita          #+#    #+#             */
/*   Updated: 2021/11/26 06:56:17 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(unsigned int n)
{
	ft_printf_num(n, "0123456789abcdef");
	return (ft_numlen(n, 16));
}

int	ft_printf_xm(unsigned int n)
{
	ft_printf_num(n, "0123456789ABCDEF");
	return (ft_numlen(n, 16));
}

int	ft_printf_p(unsigned long long int n)
{
	write (1, "0x", 2);
	ft_printf_num (n, "0123456789abcdef");
	return (ft_numlen(n, 16) + 2);
}

int	ft_printf_u(unsigned int n)
{
	ft_printf_num(n, "0123456789");
	return (ft_numlen(n, 10));
}
