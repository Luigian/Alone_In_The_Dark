/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 09:22:25 by exam              #+#    #+#             */
/*   Updated: 2020/02/04 10:45:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <stdlib.h>
*/

struct s_node
{
	int				value;
	struct s_node	**nodes;
};

void	ht_recursion(struct s_node *n, int *max, int level)
{
	int		i;
	int		x;

	i = 0;
	x = 1;
	while (n->nodes && n->nodes[i])
	{
		if (x)
		{
			++level;
			x = 0;
		}
		if (level > *max)
			*max = level;
		ht_recursion(n->nodes[i], max, level);
		++i;
	}
}

int		height_tree(struct s_node *root)
{
	int		level;
	int		max;

	if (!root)
		return (-1);
	level = 0;
	max = 0;
	ht_recursion(root, &max, level);
	return (max);
}

/*
int		main(void)
{
	struct s_node	*empty;
	struct s_node	alone;
	struct s_node	head;
	struct s_node	a;
	struct s_node	b;
	struct s_node	c;
	struct s_node	d;
	struct s_node	e;
	struct s_node	f;

	empty = NULL;
	head.value = 94;
	a.value = 34;
	b.value = 52;
	c.value = 1;
	d.value = 99;
	e.value = 11;
	f.value = 13;
	
	head.nodes = (struct s_node **)malloc(sizeof(struct s_node *) * 2);
	a.nodes = (struct s_node **)malloc(sizeof(struct s_node *) * 2);
	b.nodes = (struct s_node **)malloc(sizeof(struct s_node *));
	e.nodes = (struct s_node **)malloc(sizeof(struct s_node *));
	
	alone.nodes = NULL;
	head.nodes[0] = &a;
	head.nodes[1] = &b;
	head.nodes[2] = NULL;
	a.nodes[0] = &c;
	a.nodes[1] = &d;
	a.nodes[2] = NULL;
	b.nodes[0] = &e;
	b.nodes[1] = NULL;
	c.nodes = NULL;
	d.nodes = NULL;
	e.nodes[0] = &f;
	e.nodes[1] = NULL;
	f.nodes = NULL;

	printf("%d\n", height_tree(&head));
	printf("%d\n", height_tree(&alone));
	printf("%d\n", height_tree(empty));
	return (0);
}
*/
