/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:25:55 by sifreita          #+#    #+#             */
/*   Updated: 2022/05/19 07:19:40 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error_checking(int n)
{
	if (n == 0)
		ft_printf("pipex: Invalid number of arguments.\n");
	if (n == 1)
		ft_printf("pipex: Error in fork.\n");
	if (n == 2)
		ft_printf("pipex: Error in pipe.\n");
	if (n == 3)
		ft_printf("pipex: No such file or directory.\n");
	if (n == 4)
		ft_printf("pipex: Permission denied.\n");
	if (n == 5)
		ft_printf("Error in\n");
	exit(0);
}

char	filedir(char *fname, char **envp)
{
	char *dir;
	int i;
	char *temp;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PWD=", 4))
		i++;
	temp = envp[i] + 4;
	dir = ft_strjoin(temp, "/", fname);
	return (dir);
}

char	path(char **cmd, char **envp)
{

}

int check_file(char dir)
{
	if (access(dir, F_OK) == -1)
		ft_error_checking(3);
	if (access(dir, R_OK) == -1 || access(dir, W_OK) == -1)
		ft_error_checking(4);
	return (1);
}

void	child(int *pipe, char **argv, char **envp)
{
	int	f;
	char	**cmd;

	close(pipe[0]);
	dup2(pipe[1], 1);
	close(pipe[1]);
	check_file(filedir(argv[1], envp));
	f = open(filedir(argv[1], envp), O_RDONLY);
	dup2(f, 0);
	cmd = ft_strtrim(argv[2], " ");
	if (execve(path(cmd, envp), cmd, envp) == -1)
	{
		ft_printf("pipex: Command not found: %s.\n", cmd[0]);
		exit(0);
	}
}

void	parent(int *pipe, char **argv, char **envp)
{
	int f;
	char	**cmd;

	close(pipe[1]);
	dup2(pipe[0], 0);
	close(pipe[0]);
	f = open(filedir(argv[4], envp), O_RDWR | O_CREAT | O_TRUNC);
	dup2(f, 1);
	cmd = ft_strtrim(argv[3], " ");
	if (execve(path(cmd, envp), cmd, envp) == -1)
	{
		ft_printf("pipex: Command not found: %s.\n", cmd[0]);
		exit(0);
	}
}

int	pipex(int arg, char **argv, char **envp)
{
	int	con[2];
	pid_t	p;

	if (pipe(con) == -1)
		ft_error_checking (3);
	p = fork();
	if (p < 0)
		ft_error_checking (1);
	
	if (p == 0)
		child(con, argv, envp);
	else
	{
		wait(NULL);
		parent(con, argv, envp);
	}
	return 0;
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		ft_error_checking(0);
	pipex(argc, argv, envp);
}
