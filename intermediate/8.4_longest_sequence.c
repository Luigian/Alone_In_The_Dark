/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:49:58 by exam              #+#    #+#             */
/*   Updated: 2020/02/04 11:34:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <stdlib.h>
*/

struct s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

void	ls_recursion(struct s_node *n, int *max, int level)
{
	int		level_l;
	int		level_r;

	level_l = level;
	level_r = level;
	if (n->left)
	{
		if (n->left->value - 1 == n->value)
			++level_l;
		else
			level_l = 1;	
		if (level_l > *max)
			*max = level_l;
		ls_recursion(n->left, max, level_l);
	}
	if (n->right)
	{
		if (n->right->value - 1 == n->value)
			++level_r;
		else
			level_r = 1;	
		if (level_r > *max)
			*max = level_r;
		ls_recursion(n->right, max, level_r);
	}
}

int		longest_sequence(struct s_node *node)
{
	int		level;
	int		max;

	if (!node)
		return (0);
	level = 1;
	max = 1;
	ls_recursion(node, &max, level);
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
	head.value = 5;
	a.value = 0;
	b.value = 0;
	c.value = 1;
	d.value = 7;
	e.value = 8;
	f.value = 2;
	
	alone.left = NULL;
	alone.right = NULL;
	head.left = &a;
	head.right = &b;
	a.left = NULL;
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

	printf("%d\n", longest_sequence(&head));
	printf("%d\n", longest_sequence(&alone));
	printf("%d\n", longest_sequence(empty));
	return (0);
}
*/
