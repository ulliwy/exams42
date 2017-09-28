/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 10:12:42 by exam              #+#    #+#             */
/*   Updated: 2017/09/01 10:24:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	str = argv[1];
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			ft_putchar(*str + 32);
		else if (*str >= 'a' && *str <= 'z')
			ft_putchar(*str - 32);
		else
			ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

