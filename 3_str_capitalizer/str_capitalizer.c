/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 19:14:49 by exam              #+#    #+#             */
/*   Updated: 2017/08/18 19:52:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char	*capitalize(char *str)
{
	char	*ret;
	char	temp;

	ret = str;
	if (*str >= 'a' && *str <= 'z')
	{
		temp = *str;
		*str = temp - 32;
		str++;
	}
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z') && (is_space(*(str - 1)) == 1))
		{
			temp = *str;
			temp = temp - 32;
			*str = temp;
		}
		str++;
	}
	return (ret);
}

char	*lower(char *str)
{
	char	*ret;
	char	temp;

	ret = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			temp = *str;
			temp = temp + 32;
			*str = temp;
		}
		str++;
	}
	return ret;
}

int		main(int argc, char **argv)
{
	int		i;
	char	n;
	char	*temp;

	i = 1;
	n = '\n';
	if (argc == 1)
	{
		write(1, &n, 1);
		return (0);
	}
	while (i < argc)
	{
		temp = lower(argv[i]);
		ft_putstr(capitalize(temp));
		write(1, &n, 1);
		i++;
	}
	return (0);
}

