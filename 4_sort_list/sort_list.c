/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 19:46:58 by exam              #+#    #+#             */
/*   Updated: 2017/08/25 20:38:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		temp;
	t_list	*ret;
	t_list	*current;
	t_list	*current2;
	
	if (!lst)
		return lst;
	ret = lst;
	current = lst;
	current2 = lst;
	while (current)
	{
		current2 = current;
		while (current2)
		{
			if (cmp(current->data, current2->data) == 0)
			{
				temp = current->data;
				current->data = current2->data;
				current2->data = temp;
			}
			current2 = current2->next;
		}
		current = current->next;
	}
	return ret;
}
