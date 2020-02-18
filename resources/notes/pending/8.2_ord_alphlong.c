/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:41:51 by exam              #+#    #+#             */
/*   Updated: 2020/02/18 12:55:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Need to:
- write ft_split
- write ft_size
- sort_list function for len and alphabetical
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct		s_node
{
	char 			*str;
	int				len;
	struct s_node	*next;
}					t_node;

void	sort_list(t_node *beg)
{
	(void)beg;
}


void	ord_alphlong(char *s)
{
	int			i;
	int			size;
	t_node		*beg;
	t_node		*trav;
	
//	words = ft_split(s);
	(void)s;
	char	*words[7] = {"After", "all", "this", "time", "Always", "said", "Snape"};
	
//	size = ft_size(words);
	size = 7;

	i = 0;
	beg = malloc(sizeof(t_node));
	trav = beg;
	while (i < size)
	{
		trav->str = words[i];
		trav->len = strlen(words[i]);
		if ((i + 1) < size)
		{
			trav->next = malloc(sizeof(t_node));
			trav = trav->next;
		}
		else
			trav->next = NULL;
		++i;
	}
	trav = beg;
	while (trav)
	{
		printf("%s %d\n", trav->str, trav->len);
		trav = trav->next;
	}
	sort_list(beg);
	trav = beg;
	while (trav)
	{
		printf("%s %d\n", trav->str, trav->len);
		trav = trav->next;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ord_alphlong(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
