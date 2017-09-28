/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 20:01:58 by exam              #+#    #+#             */
/*   Updated: 2017/08/18 21:00:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_primes(int n, int i, int first)
{
	if (n == 1)
	{
		printf("\n");
		return ;
	}
	while (n % i != 0)
		i++;
	if (first == 0)
		printf("*");
	first = 0;
	printf("%d", i);
	print_primes(n / i, i, first);
}

int		main(int argc, char **argv)
{
	int		first;

	first = 1;
	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	if (atoi(argv[1]) == 1)
	{
		printf("%d\n", atoi(argv[1]));
		return (0);
	}
	print_primes(atoi(argv[1]), 2, first);
	return (0);
}

