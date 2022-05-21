/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:59:41 by sifreita          #+#    #+#             */
/*   Updated: 2022/05/19 23:15:44 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "ft_printf.h"

char	**ft_split(char const *s, char c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2, char *s3);
size_t	ft_strlen(const char *s);

int		check_file(char *dir);
char	*path(char **cmd, char **envp);
char	*search(char **paths, char *cmd);
char	*filedir(char *fname, char **envp);

int		ft_error_checking(int n);
int		pipex(char **cmd, char **envp);
void	child(int *pipe, char **cmd, char **envp);
void	parent(int *pipe, char **cmd, char **envp);

#endif