#include <stdio.h>

char    **ft_split(char *str);

int main()
{
	char	**a;
	int		i = 0;

	a = ft_split("s    f4345 d");
	while (a[i])
	{
		printf("%s\n", a[i]);
		i++;
	}
}