/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 03:35:37 by sifreita          #+#    #+#             */
/*   Updated: 2021/11/22 03:35:38 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *par, ...);

int		ft_printf_c(char c);
int		ft_printf_s(char *c);
int		ft_printf_d(int n);

int		ft_printf_x(unsigned int n);
int		ft_printf_xm(unsigned int n);
int		ft_printf_p(unsigned long long int n);
int		ft_printf_i(int n);
int		ft_printf_u(unsigned int n);

int		ft_strchr(char *str, char c);
int		ft_strlen(char *str);
int		ft_numlen(unsigned long long int n, int base);
void	ft_printf_num(unsigned long int n, char *base);

#endif