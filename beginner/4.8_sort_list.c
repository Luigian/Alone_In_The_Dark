/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:00:25 by lusanche          #+#    #+#             */
/*   Updated: 2019/08/12 22:01:14 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct 		s_list 
{
	int				data;
	struct s_list	*next;
}					t_list;

t_list	*create_list(void);
t_list		*sort_list(t_list *lst, int (*cmp)(int, int));
int		ascending(int a, int b);
void	ft_swap(int *a, int *b);
void	print_list(t_list *beg);

int		main (void)
{
	t_list	*beg;
	
	if (!(beg = create_list()))
	   return (0);	
	sort_list(beg, ascending);
	print_list(beg);
	return (0);
}

void	print_list(t_list *beg)
{
	t_list	*trav;

	trav = beg;
	while (trav)
	{
		printf("[%d]", trav->data);
		trav = trav->next;
		trav ? printf(" ") : printf("\n");
	}
}

void	ft_swap(int *a, int *b)
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

t_list	*create_list(void)
{
	t_list *beg;
	t_list *trav;
	int		dates[] = {1986, 1980, 1954, 2019, 1984, 1948};
   	int		size;
	int		i;	

	if (!(beg = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	trav = beg;
	size = 6;
	i = 0;
	while (size--)
	{
		trav->data = dates[i];
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
