/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 20:47:30 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/17 21:36:30 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void		ft_swap(int	*a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ascending(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*begin;
	t_list	*second;

	begin = lst;
	while (lst)
	{
		second = lst->next;
		while (second)
		{
			if	(!(cmp(lst->data, second->data)))
				ft_swap(&lst->data, &second->data);
			second = second->next;
		}	
		lst = lst->next;
	}
	return (begin);
}

int		main(void)
{

	t_list	*list;
	t_list	*trav;
	t_list	*beg;
	int		i;

	list = malloc(sizeof(t_list));
	trav = list;
	beg = list;
	i = 10;
	while (i)
	{
		list->data = i;
		list->next = malloc(sizeof(t_list));
		list = list->next;
		--i;
	}
	list->data = 0;
	list->next = NULL;
	while (trav)
	{
		printf("[%d] ", trav->data);
		trav = trav->next;
		++i;
	}
	printf("\n");
	sort_list(beg, ascending);
	while (beg)
	{
		printf("[%d] ", beg->data);
		beg = beg->next;
	}
	printf("\n");
	return (0);
}
