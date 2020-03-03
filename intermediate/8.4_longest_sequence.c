/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:02:07 by exam              #+#    #+#             */
/*   Updated: 2020/03/03 10:54:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <stdlib.h>
*/

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void	ls_recursion(struct s_node *node, int len, int *max)
{
	if (len > *max)
		*max = len;
	if (node->left)
	{
		if ((node->value + 1) == node->left->value)
			ls_recursion(node->left, len + 1, max);
		else
			ls_recursion(node->left, 1, max);
	}
	if (node->right)
	{
		if ((node->value + 1) == node->right->value)
			ls_recursion(node->right, len + 1, max);
		else
			ls_recursion(node->right, 1, max);
	}
}

int		longest_sequence(struct s_node *node)
{
	int		len;
	int		max;

	len = 1;
	max = len;
	if (!node)
		return (0);
	ls_recursion(node, len, &max);
	return (max);
}

/*
void	print_tree(struct s_node *node)
{
	printf("%d\n", node->value);
	if (node->left)
		print_tree(node->left);
	if (node->right)
		print_tree(node->right);
}

int		main(void)
{
	struct s_node	*empty;
	struct s_node	alone;
	empty = NULL;
	alone.left = NULL;
	alone.right = NULL;

	struct s_node a;
	struct s_node b;
	struct s_node c;
	struct s_node d;
	struct s_node e;
	struct s_node f;

	a.value = 0;
	b.value = 11;
	c.value = 0;
	d.value = 12;
	e.value = 7;
	f.value = 13;

	a.left = &b;
	a.right = NULL;
	b.left = &c;
	b.right = &d;
	c.left = &e;
	c.right = &f;
	d.left = NULL;
	d.right = NULL;
	e.left = NULL;
	e.right = NULL;
	f.left = NULL;
	f.right = NULL;
	
//	print_tree(&a);
	printf("%d\n", longest_sequence(&a));
	printf("%d\n", longest_sequence(&alone));
	printf("%d\n", longest_sequence(empty));
	return (0);
}
*/
