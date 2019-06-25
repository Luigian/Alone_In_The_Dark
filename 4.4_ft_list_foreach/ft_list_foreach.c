/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:03:11 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/10 17:53:12 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

t_list	*list_new(int size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list) * size)))
		return (NULL);
	if (!(new->data =	(char *)malloc(sizeof(char) * size)))
		return (NULL);
	new->next = NULL;
	return (new);
}

void	ft_listadd(t_list *head, t_list *tail)
{
	t_list	*temp;

	temp = head;
	temp->next = tail;
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*temp;

	temp = begin_list;
	while(temp)
	{
		f(temp->data);
		temp = temp->next;
	}
}

void	put_m(void *p)
{
	char	str[6];

	strcpy(str, p);
	*str = 'm';
	printf("%s\n", str);
}

int		main(void)
{
	t_list	*obj1;
	t_list	*obj2;

	obj1 = list_new(6);
	obj2 = list_new(6);
	obj1->data = "hello";
	obj2->data = "kilos";
	printf("%s\n", obj1->data);	
	printf("%s\n", obj2->data);	
	printf("%d\n", (int)obj1->next);	
	printf("%d\n", (int)obj2->next);	
	ft_listadd(obj1, obj2);	
	printf("%s\n", obj1->data);	
	printf("%s\n", obj2->data);	
	printf("%d\n", (int)obj1->next);	
	printf("%d\n", (int)obj2->next);	
	ft_list_foreach(obj1, put_m);	
	return (0);
}
