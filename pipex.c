/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:25:55 by sifreita          #+#    #+#             */
/*   Updated: 2022/05/19 23:51:11 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error_checking(int n)
{
	if (n == 0)
		write(3, "pipex: Invalid number of arguments.\n", 37);
	if (n == 1)
		write(3, "pipex: Error in fork.\n", 23);
	if (n == 2)
		write(3, "pipex: Error in pipe.\n", 23);
	if (n == 3)
		write(3, "pipex: No such file or directory.\n", 35);
	if (n == 4)
		write(3, "pipex: Permission denied.\n", 27);
	if (n == 5)
		write (3, "pipex: Invalid argument.\n", 26);
	exit(5);
}

void	child(int *pipe, char **argv, char **envp)
{
	int		f;
	char	**cmd;

	close(pipe[0]);
	dup2(pipe[1], 1);
	close(pipe[1]);
	check_file(filedir(argv[1], envp));
	f = open(filedir(argv[1], envp), O_RDONLY);
	dup2(f, 0);
	cmd = ft_split(argv[2], ' ');
	if (cmd[0] == NULL)
		ft_error_checking(5);
	if (execve(path(cmd, envp), cmd, envp) == -1)
	{
		write(3, "pipexp: Command not found: ", 27);
		write(3, cmd[0], ft_strlen(cmd[0]));
		write(3, ".\n", 3);
		exit(errno);
	}
}

void	parent(int *pipe, char **argv, char **envp)
{
	int		f;
	char	**cmd;

	close(pipe[1]);
	dup2(pipe[0], 0);
	close(pipe[0]);
	f = open(filedir(argv[4], envp), O_RDWR | O_CREAT, 00770);
	dup2(f, 1);
	cmd = ft_split(argv[3], ' ');
	if (cmd[0] == NULL)
		ft_error_checking(5);
	if (execve(path(cmd, envp), cmd, envp) == -1)
	{
		write(3, "pipexp: Command not found: ", 27);
		write(3, cmd[0], ft_strlen(cmd[0]));
		write(3, ".\n", 3);
		exit(errno);
	}
}

int	pipex(char **argv, char **envp)
{
	int		con[2];
	pid_t	p;
	int		errcd;

	errcd = 0;
	if (pipe(con) == -1)
		ft_error_checking (3);
	p = fork();
	if (p < 0)
		ft_error_checking (1);
	if (p == 0)
		child(con, argv, envp);
	else
	{
		waitpid(p, &errcd, 0);
		if (errcd / 256 == 5)
			exit(0);
		parent(con, argv, envp);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	dup(STDIN_FILENO);
	while (argv[i])
	{
		if (!ft_strlen(argv[i]))
			ft_error_checking(5);
		i++;
	}
	if (argc != 5)
		ft_error_checking(0);
	pipex(argv, envp);
}
