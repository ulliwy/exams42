/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:25:10 by exam              #+#    #+#             */
/*   Updated: 2017/09/01 15:45:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	was_before(char c, int len, char *str)
{
	int		i;

	i = 0;
	while(i < len)
	{
		if (*str == c)
			return (1);
		i++;
		str++;
	}
	return (0);
}

char	*lowcase(char *str)
{
	char *ret;

	ret  = str;
	while(*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str + 32;
		str++;
	}
	return ret;
}

int main(int argc, char **argv)
{
	char	*str;
	int		i;
	int 	first;
	int 	num;
	char	*temp;

	first = 1;
	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	str = argv[1];
	str = lowcase(str);
	i = 0;
	while (*str)
	{
		if ((*str >='a' && *str <= 'z') && !was_before(*str, i, argv[1]))
		{
			num = 0;
			temp = str;
			while(*temp)
			{
				if (*temp == *str)
					num += 1;
				temp++;
			}
			if (first)
			{
				printf("%d%c",  num, *str);
				first = 0;
			}
			else
				printf(", %d%c", num, *str);
		}
		str++;
		i++;
	}
	printf("\n");
}
