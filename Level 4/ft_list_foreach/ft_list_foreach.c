/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 20:41:20 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/31 13:04:24 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

t_list	*ft_lst_new(size_t size)
{
	t_list	*ls;
	
	if (!(ls = (t_list *)malloc(sizeof(t_list) * size)))
		return (NULL);
	if (!(ls->data  = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ls->data = "goal";
  	ls->next = NULL;
	return (ls);
}

void	ft_lst_add(t_list *tail, t_list *head)
{
	t_list	*temp;

	temp = head;
	temp->next = tail;
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*temp;

	temp = begin_list;
	while (temp)
	{
		f(temp->data);
		temp = temp->next;
	}
}

void	add_data(void *ptr)
{
	char	str[50];
	
	strcpy(str, ptr);
	*str = 'c';
	printf("%s\n", str);
}

int		main(void)
{
	t_list	*lst0;
	t_list	*lst1;

	lst0 = ft_lst_new(5);
	lst1 = ft_lst_new(5);
	printf("%s\n", lst0->data);	
	printf("%d\n", (int)lst0->next);	
	printf("%s\n", lst1->data);	
	printf("%d\n", (int)lst1->next);	
	ft_lst_add(lst1, lst0);
	printf("%s\n", lst0->data);	
	printf("%d\n", (int)lst0->next);	
	printf("%s\n", lst1->data);	
	printf("%d\n", (int)lst1->next);	
	ft_list_foreach(lst0, add_data);
	return (0);
}
