/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 18:20:46 by exam              #+#    #+#             */
/*   Updated: 2017/08/25 18:32:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	char *str;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	str = argv[1];
	while (*str == '\n' || *str == '\t' || *str == ' ')
		str++;
	while (*str)
	{
		if (*str == '\n' || *str == '\t' || *str == ' ')
			break;
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
	return (0);
}
