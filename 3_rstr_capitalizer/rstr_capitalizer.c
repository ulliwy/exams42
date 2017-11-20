#include <unistd.h>

void	cap(char *str)
{
	char c;

	while (*str)
	{
		if (*(str + 1) == ' ' || *(str + 1) == '\n' || *(str + 1) == '\t' || *(str + 1) == '\0')
		{
			if (*str >= 'a' && *str <= 'z')
				c = *str - 32;
			else
				c = *str;
		}
		else if (*str >= 'A' && *str <= 'Z')
			c = *str + 32;
		else
			c = *str;
		write(1, &c, 1);
		str++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	int i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return(0);
	}
	i = 1;
	while (i < argc)
	{
		cap(argv[i]);
		i++;
	}
	return (0);
}