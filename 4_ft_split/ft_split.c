#include <stdlib.h>

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char    *ft_strcpy(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = *s2;
	return (tmp);
}

int		ft_strlen(char *str)
{
	int counter;

	counter = 0;
	while (*str)
	{
		counter++;
		str++;
	}
	return (counter);
}

int		count_words(char *str)
{
	int		i;
	int		only_spaces;

	i = 0;
	only_spaces = 0;
	if (!(*str))
		return (0);
	while (is_space(*str))
		str++;
	if (!(*str))
		only_spaces = 1;
	while (*str)
	{
		if (is_space(*str) && !is_space(*(str + 1)) && *(str + 1) != '\0')
		{
			i++;
		}
		str++;
	}
	if (i == 0 && only_spaces)
		return (0);
	return (i + 1);
}

char    **ft_split(char *str)
{
	char	**arr;
	char	*temp;
	int		words;
	int		i;

	while (is_space(*str))
		str++;
	words = count_words(str);
	arr = (char **)malloc((words + 1)*sizeof(char *));
	temp = (char*)malloc(ft_strlen(str) + 1);
	temp = ft_strcpy(temp, str);
	i = 0;
	while (i < words && *temp)
	{
		arr[i] = temp;
		while (!(is_space(*temp)))
			temp++;
		if (!(*temp))
			break;
		while (is_space(*temp))
		{
			*temp = '\0';
			temp++;
		}
		if (!(*temp))
		{
			i++;
			break;
		}
		i++;
	}
	arr[i] = 0;
	return (arr);
}