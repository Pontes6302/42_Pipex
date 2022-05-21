/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:00:21 by sifreita          #+#    #+#             */
/*   Updated: 2022/05/19 23:00:25 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			return (w);
		while (s[i] != c && s[i])
			i++;
		w++;
	}
	return (w);
}

char	**ft_return(char const *s, char c, char **res)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		res[j] = ft_substr(s, start, i - start);
		j++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (0);
	res = (char **) malloc((count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (0);
	return (ft_return(s, c, res));
}
