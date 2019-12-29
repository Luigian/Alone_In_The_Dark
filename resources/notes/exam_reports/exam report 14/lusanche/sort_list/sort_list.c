/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:21:02 by exam              #+#    #+#             */
/*   Updated: 2019/08/13 10:48:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*beg;
	t_list	*second;

	beg = lst;
	while (lst)
	{
		second = lst->next;
		while (second)
		{
			if (!(cmp(lst->data, second->data)))
				swap(&(lst->data), &(second->data));
			second = second->next;
		}
		lst = lst->next;
	}
	return (beg);
}
