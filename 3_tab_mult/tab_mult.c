/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 11:01:22 by exam              #+#    #+#             */
/*   Updated: 2017/09/01 12:19:39 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_atoi(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	return (i);
}

void	ft_putnbr(int i)
{
	int temp;
	int ten;

	temp = i;
	ten = 1;
	while (temp >= 10)
	{
		temp = temp / 10;
		ten = ten * 10;	
	}
	while (ten >= 1)
	{
		ft_putchar(i / ten + '0');
		i = i % ten;
		ten = ten / 10;
	}
}

void	print_tab(int i)
{
	int j;

	j = 1;
	while (j <= 9)
	{
		ft_putnbr(j);
		ft_putstr(" x ");
		ft_putnbr(i);
		ft_putstr(" = ");
		ft_putnbr(i * j);
		ft_putstr("\n");
		j++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	char	*str;

	if (argc <  2)
	{
		ft_putchar('\n');
		return (0);
	}
	str = argv[1];
	i = ft_atoi(argv[1]);
	print_tab(i);
}
