/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:13:22 by exam              #+#    #+#             */
/*   Updated: 2019/12/24 11:08:58 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
#include <stdio.h>
*/

struct s_node
{
	int				value;
	struct s_node	**nodes;
};
/*
void	print_tree(struct s_node *root)
{
	int		i = 0;

	printf("%d", root->value);
	while (root->nodes[i])
	{
		print_tree(root->nodes[i]);
		++i;
	}
}
*/
void	count_tree(struct s_node *root, int *c, int *r)
{
	int		i;
	
	i = 0;
	while (root->nodes[i])
	{
		++*c;
		count_tree(root->nodes[i], c, r);
		++i;
	}
//	printf("%d\n", *c);
	if (*c > *r)
		*r = *c;
	*c -= 1;
}

int		height_tree(struct s_node *root)
{
	int		c[1] = {0};
	int		r[1] = {0};
	
	if (!root)
		return (-1);
	count_tree(root, c, r);
	return (*r);
}
/*
struct s_node 	*init_node(void)
{
	struct s_node	*n;
	
	n = (struct s_node*)malloc(sizeof(struct s_node) * 1);
	n->nodes = (struct s_node **)malloc(sizeof(struct s_node *) * 1);
	n->nodes[0] = (struct s_node *)malloc(sizeof(struct s_node) * 1);
	n->nodes[1] = (struct s_node *)malloc(sizeof(struct s_node) * 1);
	return (n);
}

int		main(void)
{
	struct s_node	*root;
	struct s_node	*n1;
	struct s_node	*n2;
	struct s_node	*n3;
	struct s_node	*n4;
	struct s_node	*n5;
	struct s_node	*n6;
	struct s_node	*single;
	struct s_node	*empty;

	root = init_node();
	n1 = init_node();
	n2 = init_node();
	n3 = init_node();
	n4 = init_node();
	n5 = init_node();
	n6 = init_node();
	single = init_node();
	empty = NULL;
	
	root->value = 94;
	root->nodes[0] = n1;
	root->nodes[1] = n2;
	root->nodes[2] = NULL;

	n1->value = 34;
	n1->nodes[0] = n3;
	n1->nodes[1] = n4;
	n1->nodes[2] = NULL;
	
	n3->value = 1;
	n3->nodes[0] = NULL;
	
	n4->value = 99;
	n4->nodes[0] = NULL;
	
	n2->value = 52;
	n2->nodes[0] = n5;
	n2->nodes[1] = NULL;
	
	n5->value = 11;
	n5->nodes[0] = n6;
	n5->nodes[1] = NULL;
	
	n6->value = 13;
	n6->nodes[0] = NULL;
	
	single->value = 7;
	single->nodes[0] = NULL;

	print_tree(root);
	printf("\n");
	
	printf("%d\n", height_tree(single));
	printf("%d\n", height_tree(empty));
	printf("%d\n", height_tree(root));
	return (0);
}*/
