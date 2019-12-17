/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:03:11 by lusanche          #+#    #+#             */
/*   Updated: 2019/08/12 21:38:27 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list	*create_list(void);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
void	put_m(void *p);

int		main(void)
{
	t_list	*beg;
	
	if (!(beg = create_list()))
		return (0);
	ft_list_foreach(beg, put_m);	
	return (0);
}

void	put_m(void *p)
{
	char	str[10];

	strcpy(str, p);
	*str = 'm';
	printf("%s\n", str);
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

t_list	*create_list(void)
{
	t_list	*beg;
	t_list	*trav;
	char	*names[] = { "Pepe", "Cristy", "Pancho", "Maria", "Luis" };
	int		size;
	int		i;

	if (!(beg = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	trav = beg;
	size = 5;
	i = 0;
	while (size--)
	{
		trav->data = names[i];
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
