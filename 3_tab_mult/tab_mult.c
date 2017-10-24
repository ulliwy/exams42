#include <unistd.h>

void	print_nbr(int i, int first)
{
	char k;

	if (!i && first)
	{
		write(1, "0", 1);
		return ;
	}
	if (i > 0)
	{
		print_nbr(i / 10, 0);
		k = i % 10 + '0';
		write(1, &k, 1);
	}
	return ;
}

int		main(int argc, char **argv)
{
	char *str;
	int i;
	int j;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = argv[1];
	i = 0;
	while (*str)
	{
		i = 10 * i + *str - '0';
		str++;
	}
	j = 1;
	while (j <= 9)
	{
		print_nbr(j, 1);
		write(1, " x ", 3);
		print_nbr(i, 1);
		write(1, " = ", 3);
		print_nbr(i * j, 1);
		write(1, "\n", 1);
		j++;
	}
}
