#include <unistd.h>

int		main(int argc, char **argv)
{
	char	*str;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = argv[1];
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
	return (0);
}