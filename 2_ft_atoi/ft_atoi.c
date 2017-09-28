/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 18:40:57 by exam              #+#    #+#             */
/*   Updated: 2017/08/25 18:57:58 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int	sign;
	int	value;
	int	was_sign;

	sign = 1;
	was_sign = 0;
	while (*str == '\n' || *str == '\t' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		was_sign = 1;
		str++;
	}
	if (*str == '+' && !(was_sign))
	{
		sign = 1;
		str++;
	}
	value = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (value * sign);
		value = value * 10 + (*str - '0');
		str++;
	}
	return (value * sign);
}
