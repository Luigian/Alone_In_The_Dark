/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:03:56 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/23 14:21:43 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

int		comparation(void *a, void *b)
{
	if (a == b)
		return (0);
	else
		return (1);
}

/*
void	ft_list_remove_if(t_list **begin_list, int data_ref, int (*cmp)())
{
	t_list	*curr;
	t_list	*tmp;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		curr = *begin_list;
		*begin_list = (*begin_list)->next;
		free(curr);
	}
	curr = *begin_list;
	while (curr && curr->next)
	{
		if (cmp(curr->next->data, data_ref) == 0)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			free(tmp);
		}
		else
			curr = curr->next;
	}
}
*/

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*trav;
	t_list	*post;

	while (*begin_list && !(cmp((*begin_list)->data, data_ref)))
	{
		trav = *begin_list;
		*begin_list = (*begin_list)->next;
		free(trav);
	}
	trav = *begin_list;
	while (trav && trav->next)
	{
		if (!(cmp(trav->next->data, data_ref)))
		{
			post = trav->next;
			trav->next = post->next;
			free(post);
		}
		else
			trav = trav->next;
	}
}

int		main (void)
{
	t_list	*beg;
	t_list	*create;
	t_list	*print;
	void	*ref;
	int		size;
	int		i;
	char 	*name[] = { "Jan", "Feb", "Mar", "Abr", "May", "Jun" };

	beg = malloc(sizeof(t_list) * 4);
	create = beg;
	print = beg;
	ref =  "Feb"; 
	size = 5;
	i = 0;
	while (size--)
	{
		create->data = name[i++];
		create->next = malloc(sizeof(t_list) * 4);
		create = create->next;
	}
	create->data = name[i];
	create->next = NULL;
	while (print)
	{
		printf("[%s]", print->data);
		print = print->next;
	}
	printf("\n");
	
	ft_list_remove_if(&beg, ref, comparation);
	
	print = beg;
	while (print)
	{
		printf("[%s]", print->data);
		print = print->next;
	}
	printf("\n");
	return (0);
}
