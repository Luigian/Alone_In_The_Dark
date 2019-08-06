/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:00:25 by lusanche          #+#    #+#             */
/*   Updated: 2019/08/05 21:24:26 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct 		s_list 
{
	int				data;
	struct s_list	*next;
}					t_list;

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_list		*sort_list(t_list *lst, int (*cmp)(int, int))
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

int		ascending(int a, int b)
{
	return (a <= b);
}

int		main (void)
{
	t_list	*list;
	t_list	*beg;
	t_list	*trav;
	int		i;
	
	list = malloc(sizeof(t_list) * 4);
	beg = list;
	trav = list;
	i = 10;
	while (i)
	{
		list->data = i;
		list->next = malloc(sizeof(t_list) * 4);
		list = list->next;
		--i;
	}
	list->data = i;
	list->next = NULL;
	while (trav)
	{
		printf("[%d]", trav->data);
		trav = trav->next;
	}
	printf("\n");
	sort_list(beg, ascending);
	while (beg)
	{
		printf("[%d]", beg->data);
		beg = beg->next;
	}
	printf("\n");
	return (0);
}
