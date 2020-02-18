/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:45:52 by exam              #+#    #+#             */
/*   Updated: 2020/02/18 11:31:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

struct s_node
{
	int				value;
	struct s_node	*next;
};

int		hashn(int node)
{
	if (node < 0)
	{
		node *= -1;
		++node;
	}
	return (node % 1000000);
}

int		is_looping(struct s_node *node)
{
	int		a[1000000];
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (i < 1000000)
		a[i++] = 0;
	while (node)
	{
//		printf("%d\n", node->value);
//		printf("%p\n", node);
//		printf("%d\n", (int)node);
		n = hashn((int)node);
//		printf("%d\n", n);
		if (a[n])
			return (1);
		a[n] += 1;
		node = node->next;
	}
	return (0);
}

/*
int		is_already(struct s_node *node, struct s_node *t[10], int i)
{
	while (i--)
	{
		if (t[i] == node)
			return (1);
	}
	return (0);
}
		

int		is_looping(struct s_node *node)
{
	struct s_node	*t[10];
	int		i;

	i = 0;
	while (node)
	{
		printf("%d\n", node->value);
		printf("%p\n", node);
		if (is_already(node, t, i))
			return (1);
		t[i] = node;
		node = node->next;
		++i;
	}
	return (0);
}
*/

/*
int		main(void)
{
	struct s_node	a;
	struct s_node	b;
	struct s_node	c;
	struct s_node	d;

	a.value = 1;
	b.value = 2;
	c.value = 3;
	d.value = 4;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &a;
	printf("R = %d\n", is_looping(&a));
	return (0);
}
*/
