/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 12:57:12 by exam              #+#    #+#             */
/*   Updated: 2017/09/01 14:19:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned char c)
{
	char	base[17] = "0123456789abcdef";

	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

void	print_char(unsigned char *temp, int *j, int size)
{
	int count;

	count = 0;
	while (*j < size && count < 16)
	{
		if (temp[*j] >= 32 && temp[*j] <= 126)
			ft_putchar(temp[*j]);
		else
			ft_putchar('.');
		(*j)++;
		count ++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	int				i;
	int				j;
	unsigned char	*temp;

	i = 0;
	j = 0;
	temp = (unsigned char*)addr;
	while (i < (int)size || i % 16 != 0)
	{
		if (i && i % 2 == 0)
			ft_putchar(' ');
		if (i && i % 16 == 0)
		{
			print_char(temp, &j, (int)size);
			ft_putchar('\n');
		}
		if (i >= (int)size)
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		else
			print_hex(temp[i]);
		i++;
	}
	if (j < (int)size)
	{
		ft_putchar(' ');
		print_char(temp, &j, (int)size);
	}
	ft_putchar('\n');
}

