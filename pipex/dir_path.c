/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:39:30 by sifreita          #+#    #+#             */
/*   Updated: 2022/05/19 23:09:41 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*filedir(char *fname, char **envp)
{
	int		i;
	char	*dir;
	char	*temp;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PWD=", 4))
		i++;
	temp = envp[i] + 4;
	dir = ft_strjoin(temp, "/", fname);
	return (dir);
}

char	*search(char **paths, char *cmd)
{
	int		i;
	char	*temp;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/", cmd);
		if (temp && access(temp, F_OK) == 0)
			return (temp);
		if (temp)
			free(temp);
		i++;
	}
	return (0);
}

char	*path(char **cmd, char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (search(paths, cmd[0]));
}

int	check_file(char *dir)
{
	if (access(dir, F_OK) == -1)
		ft_error_checking(3);
	if (access(dir, R_OK) == -1 || access(dir, W_OK) == -1)
		ft_error_checking(4);
	return (1);
}
