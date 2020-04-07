#include <stdlib.h>
#include <stdio.h>

struct s_node {
	int		value;
	struct s_node	*left;
	struct s_node	*right;
};

void	print_tree(struct s_node *root)
{
	printf("%d\n", root->value);
	if (root->left)
		print_tree(root->left);
	if (root->right)
		print_tree(root->right);
}

void	ls_recursion(struct s_node *node, int len, int *max)
{
	if (node->left)
	{
		if (node->value + 1 == node->left->value)
			ls_recursion(node->left, len + 1, max);
		else
			ls_recursion(node->left, 1, max);
	}
	if (node->right)
	{
		if (node->value + 1 == node->right->value)
			ls_recursion(node->right, len + 1, max);
		else
			ls_recursion(node->right, 1, max);
	}
	if (len > *max)
		*max = len;
}

int	longest_sequence(struct s_node *node)
{
	int	len;
	int	max;

	len = 1;
	max = 1;
	if (!node)
		return (0);
	ls_recursion(node, len, &max);
	return (max);
}

int	main(void)
{
	struct s_node	n1;
	struct s_node	n2;
	struct s_node	n3;
	struct s_node	n4;
	struct s_node	n5;
	struct s_node	n6;
	struct s_node	*n7 = NULL;

	n1.value = 10;
	n2.value = 5;
	n3.value = 6;
	n4.value = 9;
	n5.value = 7;
	n6.value = 13;

	n1.left = &n2;
	n1.right = NULL;
	n2.left = &n3;
	n2.right = &n4;
	n3.left = &n5;
	n3.right = &n6;
	n4.left = NULL;
	n4.right = NULL;
	n5.left = NULL;
	n5.right = NULL;
	n6.left = NULL;
	n6.right = NULL;

//	print_tree(&n1);
	printf("%d\n", longest_sequence(&n1));
	printf("%d\n", longest_sequence(&n3));
	printf("%d\n", longest_sequence(&n6));
	printf("%d\n", longest_sequence(n7));
	return (0);
}
