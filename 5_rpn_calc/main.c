#include <stdio.h>
#include <stdlib.h>

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int		is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int		calc_words(char *str)
{
	int w;

	w = 0;
	while (*str)
	{
		if (!is_space(*str) && (is_space(*(str + 1)) || !(*(str + 1))))
			w++;
		str++;
	}
	return (w);
}
int		is_number(char *str)
{
	if ((*str == '+' || *str == '-') && !(*(str + 1)))
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (is_digit(*str))
		str++;
	if (*str)
		return (0);
	else
		return (1);
}

int		is_op(char *str)
{
	return ((*str == '+' || *str == '-' || *str == '/' || *str == '*' || *str == '%') && (!(*(str + 1))));
}

int		doop(char c, int value1, int value2)
{
	if (c == '+')
		return (value1 + value2);
	else if (c == '-')
		return (value1 - value2);
	else if (c == '*')
		return (value1 * value2);
	else if (c == '/')
		return (value1 / value2);
	else
		return (value1 % value2);
}

int		main(int argc, char **argv)
{
	int		words;
	char	*str;
	char	**arr;
	int		i;

	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	str = argv[1];
	words = calc_words(str);
	arr = (char **)malloc(sizeof(char *) * words);
	while (is_space(*str))
		str++;
	i = 0;
	while (*str)
	{
		if (!is_space(*str))
		{
			arr[i] = str;
			while(!is_space(*str) && *str)
				str++;
			*str = '\0';
			i++;
		}
		str++;
	}

	if (words == 1)
	{
		str = arr[0];
		if ((*str == '+' || *str == '-') && !(*(str + 1)))
		{
			printf("Error\n");
			return (0);
		}
		if (*str == '+' || *str == '-')
			str++;
		while (is_digit(*str))
			str++;
		if (*str)
		{
			printf("Error\n");
			return (0);
		}
		else
		{
			printf("%d\n", atoi(arr[0]));
			return (0);
		}
	}
	i = 0;
	int v = 0;
	int v1;
	int v2;
	int values[100] = {0};
	while (i < words)
	{
		if (is_number(arr[i]))
		{
			values[v] = atoi(arr[i]);
			v++;
		}
		else if (is_op(arr[i]))
		{
			if (v < 2)
			{
				printf("Error\n");
				return (0);
			}
			v1 = values[v - 2];
			v2 = values[v - 1];
			if ((arr[i][0] == '/' || arr[i][0] == '%') && v2 == 0)
			{
				printf("Error\n");
				return (0);
			}
			values[v - 2] = doop(arr[i][0], v1, v2);
			v--;
		}
		else
		{
			printf("Error\n");
			return (0);
		}
		i++;
	}
	if (v != 1)
	{
		printf("Error\n");
		return (0);
	}
	printf("%d\n", values[0]);
	free(arr);
	return (0);
}