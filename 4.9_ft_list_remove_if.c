/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:43:02 by lusanche          #+#    #+#             */
/*   Updated: 2019/08/05 20:25:21 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

int			comparation(void *a, void *b);
void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
void		print_list(t_list *beg);
t_list		*create_list(void);

int		main(void)
{
	t_list		*beg;
	void		*reference;

	if (!(beg = create_list()))
		return (0);
	print_list(beg);
	reference = "Feb";
	ft_list_remove_if(&beg, reference, comparation);
	print_list(beg);
	return (0);
}

int		comparation(void *a, void *b)
{
	return (a == b ? 0 : 1);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list		*trav;
	t_list		*post;

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

void	print_list(t_list *beg)
{
	t_list		*trav;

	trav = beg;
	while (trav)
	{
		printf("[%s]", trav->data);
		trav = trav->next;
		trav ? printf(" ") : printf("\n");
	}
}

t_list	*create_list(void)
{
	t_list		*beg;
	t_list		*trav;
	char		*months[] = { "Jan", "Feb", "Mar", "Apr", "May" };
	int			size;
	int			i;

	if (!(beg = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	trav = beg;
	size = 5;
	i = 0;
	while (size--)
	{
		trav->data = months[i];
		++i;
		if (size)
		{
			if (!(trav->next = (t_list *)malloc(sizeof(t_list) * 1)))
				return (NULL);
			trav = trav->next;
		}
		else
			trav->next = NULL;
	}
	return (beg);
}
