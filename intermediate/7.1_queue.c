/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:22:29 by exam              #+#    #+#             */
/*   Updated: 2020/03/03 10:00:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
#include <stdio.h>
*/

struct s_queue
{
	struct s_node *first;
	struct s_node *last;
};

struct s_node
{
	void *content;
	struct s_node *next;
};

struct s_queue	*init(void)
{
	struct s_queue	*q;

	q = malloc(sizeof(struct s_queue));
	q->first = NULL;
	q->last = NULL;
	return (q);
}

struct s_node	*init_node(void *content)
{
	struct s_node	*n;

	n = malloc(sizeof(struct s_node));
	n->content = content;
	n->next = NULL;
	return (n);
}

void	enqueue(struct s_queue *queue, void *content)
{
	struct s_node	*n;
	
	n = init_node(content);
	if (queue->first == NULL)
	{
		queue->first = n;
		queue->last = n;
	}
	else
	{
		queue->last->next = n;
		queue->last = n;
	}
}

void	*dequeue(struct s_queue *queue)
{
	void	*ret;

	if (queue->first == NULL)
		return (NULL);
	ret = queue->first->content;
	if (queue->first->next == NULL)
		queue->last = NULL;
	queue->first = queue->first->next;
	return (ret);
}

void	*peek(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (NULL);
	return (queue->first->content);
}

int		isEmpty(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (1);
	return (0);
}

/*
int		main(void)
{
	struct s_queue	*q;

	q = init();
	printf("%p\n", q->first);
	printf("%p\n", q->last);
	enqueue(q, "Omega");
	printf("%p\n", q->first);
	printf("%p\n", q->last);
	printf("%s\n", q->last->content);
	printf("%s\n", dequeue(q));
	printf("%s\n", dequeue(q));
	enqueue(q, "Upcycle");
	printf("%s\n", peek(q));
	printf("%d\n", isEmpty(q));
	printf("%s\n", dequeue(q));
	printf("%d\n", isEmpty(q));
	return (0);
}
*/
