#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

void	rot(char *str)
{
	char	*begin;
	int		printed;

	begin = str;
	printed = 0;
	while (*str && is_space(*str))
		str++;
	while (*str && !is_space(*str))
		str++;
	while (*str && is_space(*str))
		str++;
	while (*str)
	{
		if (is_space(*str) && is_space(*(str + 1)))
			str++;
		else
		{
			write(1, str, 1);
			printed = 1;
			str++;
		}
	}
	if (printed)
		write(1, " ", 1);
	while (*begin && is_space(*begin))
		begin++;
	while (*begin &&  !is_space(*begin))
	{
		write(1, begin, 1);
		begin++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		rot(argv[i]);
		i++;
	}
	return (0);
}