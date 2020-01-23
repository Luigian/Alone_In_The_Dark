/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:21:18 by exam              #+#    #+#             */
/*   Updated: 2020/01/23 11:45:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

struct s_node
{
	int				value;
	struct s_node	*right;
	struct s_node 	*left;
};

void	reverse_tree(struct s_node *root)
{
	struct	s_node	*temp;

	temp = root->left;
	root->left = root->right;
	root->right = temp;

	if (root->left)
		reverse_tree(root->left);
	if (root->right)
		reverse_tree(root->right);
}

/*
void	print_tree(struct s_node *root)
{
	printf("%d\n", root->value);
	if (root->left)
		print_tree(root->left);
	if (root->right)
		print_tree(root->right);
}

int		main(void)
{
	struct	s_node	root;
	struct	s_node	a;
	struct	s_node	b;
	struct	s_node	c;
	struct	s_node	d;
	struct	s_node	e;
	struct	s_node	f;

	root.value = 1;
	a.value = 2;
	b.value = 3;
	c.value = 4;
	d.value = 5;
	e.value = 6;
	f.value = 7;
	
	root.left = &a;
	root.right = &b;
	a.left = &c;
	a.right = &d;
	b.left = &e;
	b.right = &f;
	c.left = NULL;
	c.right = NULL;
	d.left = NULL;
	d.right = NULL;
	e.left = NULL;
	e.right = NULL;
	f.left = NULL;
	f.right = NULL;

	print_tree(&root);
	reverse_tree(&root);
	print_tree(&root);
	return (0);
}
*/
