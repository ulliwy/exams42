/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 10:36:08 by exam              #+#    #+#             */
/*   Updated: 2017/09/01 10:46:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	wrapper(unsigned char octet, int i)
{
	if (i > 7)
		return ;
	wrapper(octet / 2, i + 1);
	ft_putchar(octet % 2 + '0');
}

void	print_bits(unsigned char octet)
{
	int		i;

	i = 0;
	wrapper(octet, i);
}
