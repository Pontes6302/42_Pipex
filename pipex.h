#ifndef PIPEX_H
# define PIPEX_H

# define BUFFER_CONVERT 100
# define BUFFER_READ 100000
# define FLAGS_CHILD O_RDWR
# define FLAGS_PARENT O_CREAT

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "printf/ft_printf.h"

char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strcpy(char *dst, char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, char *src, int dstsize);
char	*ft_strjoin(char *s1, char *s2, char *s3);

int		ft_error_checking(int n);
void	child(int *pipe, char **cmd, char **envp);
void	parent(int *pipe, char **cmd, char **envp);
int		pipex(int arg, char **cmd, char **envp);

#endif