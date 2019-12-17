/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:28:24 by exam              #+#    #+#             */
/*   Updated: 2019/12/17 11:08:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
#include <stdio.h>
*/
struct s_node
{
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

void	reverse_tree(struct s_node *root)
{
	struct s_node	*temp;

	temp = root->left;
	root->left = root->right;
	root->right = temp;
	
	if (root->left)
		reverse_tree(root->left);
	if (root->right)
		reverse_tree(root->right);
}
/*
void	print_tree(struct s_node *n)
{
	printf("%d\n", n->value);
	if (n->left)
		print_tree(n->left);
	if (n->right)
		print_tree(n->right);
}

int		main(void)
{
	struct s_node	n1;
	struct s_node	n2;
	struct s_node	n3;
	struct s_node	n4;
	struct s_node	n5;
	struct s_node	n6;
	struct s_node	n7;
	struct s_node	n8;
	struct s_node	n9;
	struct s_node	n10;
	struct s_node	n11;

	n1.value = 94;
	n1.left = &n2;
	n1.right = &n3;

	n2.value = 34;
	n2.left = &n4;
	n2.right = &n5;
	
	n3.value = 52;
	n3.left = NULL;
	n3.right = NULL;
	
	n4.value = 1;
	n4.left = &n6;
	n4.right = NULL;
	
	n5.value = 99;
	n5.left = &n7;
	n5.right = &n8;
	
	n6.value = 20;
	n6.left = NULL;
	n6.right = NULL;
	
	n7.value = 83;
	n7.left = NULL;
	n7.right = &n9;
	
	n8.value = 39;
	n8.left = &n10;
	n8.right = &n11;
	
	n9.value = 61;
	n9.left = NULL;
	n9.right = NULL;
	
	n10.value = 37;
	n10.left = NULL;
	n10.right = NULL;
	
	n11.value = 67;
	n11.left = NULL;
	n11.right = NULL;

	print_tree(&n1);
	reverse_tree(&n1);
	print_tree(&n1);
	printf("\n%d\n", n1.right->left->right->left->value);
	return (0);
}
*/