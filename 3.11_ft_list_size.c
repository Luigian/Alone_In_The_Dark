/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 09:49:37 by exam              #+#    #+#             */
/*   Updated: 2019/08/26 21:41:28 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list	*create_list(void);
int		ft_list_size(t_list *begin_list);

int		main(void)
{
	t_list		*beg;

	if (!(beg = create_list()))
		return (0);
	printf("%d\n", ft_list_size(beg));
	return (0);
}

int		ft_list_size(t_list *begin_list)
{
	t_list	*trav;
	int		counter;

	trav = begin_list;
	counter = 0;
	while (trav)
	{
		++counter;
		trav = trav->next;
	}
	return (counter);
}

t_list	*create_list(void)
{
	t_list		*beg;
	t_list		*trav;
	char		*months[] = { "John", "Frank", "Mark", "April", "Maria" };
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
