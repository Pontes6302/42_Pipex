#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

int main ()
{
	char *test;

	test = ft_strjoin("Primeiro, ", "Segundo     :", "teste");
	printf("%s", test);
}