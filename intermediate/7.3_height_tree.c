/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 09:35:54 by exam              #+#    #+#             */
/*   Updated: 2020/03/10 10:22:41 by exam             ###   ########.fr       */
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

void	ht_recursion(struct s_node *node, int len, int *max)
{
	int		i;
	
	if (len > *max)
		*max = len;
	i = 0;
	while (node->nodes && node->nodes[i])
	{
		ht_recursion(node->nodes[i], len + 1, max);
		++i;
	}
}

int		height_tree(struct s_node *root)
{
	int		max[1] = {0};
	int		i;
	
	if (!root)
		return (-1);
	i = 0;
	while (root->nodes && root->nodes[i])
	{
		ht_recursion(root->nodes[i], 1, max);
		++i;
	}
	return (*max);
}

/*
void	print_tree(struct s_node *node)
{
	int		i;

	printf("%d\n", node->value);
	i = 0;
	while (node->nodes && node->nodes[i])
	{
		print_tree(node->nodes[i]);
		++i;
	}
}
*/
/*
int		main(void)
{
	struct s_node	*empty;
	empty = NULL;
	
	struct s_node	a;	
	struct s_node	b;	
	struct s_node	c;	
	struct s_node	d;	
	struct s_node	e;	
	struct s_node	f;	
	struct s_node	g;
	
	a.value = 94;
	b.value = 34;
	c.value = 52;
	d.value = 1;
	e.value = 99;
	f.value = 11;
	g.value = 13;
	
	a.nodes = malloc(sizeof(struct s_node) * 2);
	b.nodes = malloc(sizeof(struct s_node) * 2);
	c.nodes = malloc(sizeof(struct s_node));
	f.nodes = malloc(sizeof(struct s_node));
	d.nodes = NULL;
	e.nodes = NULL;
	g.nodes = NULL;

	a.nodes[0] = &b;
	a.nodes[1] = &c;
	a.nodes[2] = NULL;
	b.nodes[0] = &d;
	b.nodes[1] = &e;
	b.nodes[2] = NULL;
	c.nodes[0] = &f;
	c.nodes[1] = NULL;
	f.nodes[0] = &g;
	f.nodes[1] = NULL;

//	print_tree(&a);
	printf("%d\n", height_tree(&a));
	printf("%d\n", height_tree(empty));
	printf("%d\n", height_tree(&g));
	return (0);
}
*/
