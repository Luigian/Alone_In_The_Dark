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
*/
/*
int		main(void)
{
	struct s_node	*x;
	x = NULL;
		
	struct s_node	a;
	struct s_node	b;
	struct s_node	c;
	struct s_node	d;
	struct s_node	e;
	struct s_node	f;
	struct s_node	g;
	struct s_node	h;

	a.value = 5;
	b.value = 6;
	c.value = 4;
	d.value = 7;
	e.value = 3;
	f.value = 3;
	g.value = 2;
	h.value = 2;

	a.left = &b;
	a.right = &c;
	b.left = NULL;
	b.right = NULL;
	c.left = &d;
	c.right = &e;
	d.left = &f;
	d.right = &g;
	e.left = NULL;
	e.right = &h;
	f.left = NULL;
	f.right = NULL;
	g.left = NULL;
	g.right = NULL;
	h.left = NULL;
	h.right = NULL;

//	print_tree(&a);
	printf("%d\n", longest_sequence(&a));
	printf("%d\n", longest_sequence(&c));
	printf("%d\n", longest_sequence(x));
	return (0);
}
*/
