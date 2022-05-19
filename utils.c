/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:29:52 by sifreita          #+#    #+#             */
/*   Updated: 2022/05/19 07:06:52 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (c == 0)
		return ((char *)s + ft_strlen(s));
	i = 0;
	while (s[i])
	{
		if (((unsigned char)c) == ((unsigned char *)s)[i])
			return (((char *)s) + i);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (start >= ft_strlen(s))
	{
		res = malloc(sizeof(char));
		if (!res)
			return (0);
		*res = '\0';
		return (res);
	}
	if (ft_strlen(s) < len)
		return (ft_strdup((char *)s + start));
	res = (char *)malloc(len + 1 * sizeof(char));
	if (!res)
		return (0);
	while (start < ft_strlen(s) && i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

int	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	unsigned int	i;

	i = 0;
	s11 = (unsigned char *) s1;
	s22 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while ((s11[i] || s22[i]) && s11[i] == s22[i] && i < n - 1)
		i++;
	return (s11[i] - s22[i]);
}

size_t	ft_strlcat(char *dst, char *src, int dstsize)
{
	int	p;
	int	s;
	int	l;

	s = 0;
	p = 0;
	l = ft_strlen(src);
	while (dst[s] && s < dstsize)
		s++;
	while (src[p] && (p + s + 1) < (dstsize))
	{
		dst[p + s] = src[p];
		p++;
	}
	if (s < dstsize)
		dst[s + p] = '\0';
	return (l + s);
}

char	*ft_strjoin(char *s1, char *s2, char *s3)
{
	char	*res;
	int		i;
	int		t;

	i = -1;
	res = malloc((ft_strlen(s1) * sizeof(char))
			+ (ft_strlen(s2) * sizeof(char)) + (ft_strlen(s3) * sizeof(char)));
	if (!res)
		return (0);
	while (s1[++i])
		res[i] = s1[i];
	t = i;
	i = -1;
	while (s2[++i])
		res[i + t] = s2[i];
	t = t + i;
	i = -1;
	while (s3[++i])
		res[i + t] = s3[i];
	res[i + t] = '\0';
	return (res);
}