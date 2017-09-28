/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 18:22:05 by exam              #+#    #+#             */
/*   Updated: 2017/08/18 18:42:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	rotate(char c)
{
	char	temp;

	temp = c;
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		if (c == 'z')
			temp = 'a';
		else if (c == 'Z')
			temp = 'A';
		else
		{
			temp = c;
			temp = temp + 1;
		}
	}
	return temp;
}

int		main(int argc, char **argv)
{
	int		i;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	while (argv[1][i] != 0)
	{
		ft_putchar(rotate(argv[1][i]));
		i++;
	}
	ft_putchar('\n');
	return (0);
}

