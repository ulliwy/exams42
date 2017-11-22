#include <unistd.h>

int		is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int		main(int argc, char **argv)
{
	char *str;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = argv[1];
	while (is_space(*str))
		str++;
	while (*str)
	{
		if (!is_space(*str))
			write(1, str, 1);
		else if (is_space(*str) && !is_space(*(str + 1)) && *(str + 1))
			write(1, " ", 1);
		str++;
	}
	write(1, "\n", 1);
	return (0);
}
