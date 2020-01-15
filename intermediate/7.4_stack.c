/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:44:24 by exam              #+#    #+#             */
/*   Updated: 2020/01/14 11:39:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
#include <stdio.h>
*/

struct s_node
{
	void			*content;
	struct s_node 	*next;
};

struct s_stack
{
	struct s_node	*top;
};

struct s_stack	*init(void)
{
	struct s_stack	*s;

	s = malloc(sizeof(struct s_stack));
	s->top = NULL;
	return (s);
}

struct s_node	*init_node(void *data)
{
	struct s_node	*n;

	n = malloc(sizeof(struct s_node));
	n->content = data;
	n->next = NULL;
	return (n);
}

void	*pop(struct s_stack *stack)
{
	void	*ret;

	if (stack->top == NULL)
		return (NULL);
	ret = stack->top->content;
	stack->top = stack->top->next;
	return (ret);
}

void	push(struct s_stack *stack, void *content)
{
	struct s_node	*n;
	
	n = init_node(content);
	if (stack->top == NULL)
		stack->top = n;
	else
	{
		n->next = stack->top;
		stack->top = n;
	}
}

void	*peek(struct s_stack *stack)
{
	if (stack->top == NULL)
		return (NULL);
	return (stack->top->content);
}

int		isEmpty(struct s_stack *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}

/*
int		main(void)
{
	struct s_stack	*s;

	s = init();
	printf("no address: %p\n", s->top);
	push(s, "Peter");
	printf("yes address: %p\n", s->top);
	printf("peek: %s\n", peek(s));
	printf("yes address: %p\n", s->top);
	printf("pop: %s\n", pop(s));
	printf("no address: %p\n", s->top);
	printf("one: %d\n", isEmpty(s));
	return (0);
}
*/
