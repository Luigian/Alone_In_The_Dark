#include <stdlib.h>
#include <stdio.h>

struct s_node {
	int		value;
	struct s_node	**nodes;
};

void	print_tree(struct s_node *root)
{
	int	i;

	printf("%d\n", root->value);
	i = 0;
	while (root->nodes && root->nodes[i])
	{
		print_tree(root->nodes[i]);
		++i;
	}
}

void	ht_recursion(struct s_node *node, int len, int *max)
{
	int	i;

	i = 0;
	while (node->nodes && node->nodes[i])
	{
		ht_recursion(node->nodes[i], len + 1, max);
		++i;
	}
	if (len > *max)
		*max = len;
}	

int	height_tree(struct s_node *root)
{
	int	len;
	int	max;

	len = 0;
	max = 0;
	if (!root)
		return (-1);
	ht_recursion(root, len, &max);
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
	struct s_node	n7;
	struct s_node	*n8 = NULL;

	n1.value = 94;
	n2.value = 34;
	n3.value = 52;
	n4.value = 1;
	n5.value = 99;
	n6.value = 11;
	n7.value = 13;
	
	n1.nodes = malloc(sizeof(struct s_node *) * 3);
	n2.nodes = malloc(sizeof(struct s_node *) * 3);
	n3.nodes = malloc(sizeof(struct s_node *) * 2);
	n6.nodes = malloc(sizeof(struct s_node *) * 2);

	n1.nodes[0] = &n2;
	n1.nodes[1] = &n3;
	n1.nodes[2] = NULL;
	n2.nodes[0] = &n4;
	n2.nodes[1] = &n5;
	n2.nodes[2] = NULL;
	n3.nodes[0] = &n6;
	n3.nodes[1] = NULL;
	n4.nodes = NULL;
	n5.nodes = NULL;
	n6.nodes[0] = &n7;
	n6.nodes[1] = NULL;
	n7.nodes = NULL;

//	print_tree(&n1);
	printf("%d\n", height_tree(&n1));
	printf("%d\n", height_tree(&n7));
	printf("%d\n", height_tree(n8));
	return (0);
}
