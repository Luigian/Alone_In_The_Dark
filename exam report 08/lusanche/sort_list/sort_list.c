/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 09:57:04 by exam              #+#    #+#             */
/*   Updated: 2019/06/25 10:50:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*begin;
	t_list	*second;

	begin = lst;
	while (lst)
	{
		second = lst->next;
		while (second)
		{
			if (!(cmp(lst->data, second->data)))
				ft_swap(&(lst->data), &(second->data));
			second = second->next;
		}
		lst = lst->next;
	}
	return (begin);
}
