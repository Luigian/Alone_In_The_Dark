/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 09:18:21 by exam              #+#    #+#             */
/*   Updated: 2019/11/26 10:47:10 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
#include <stdio.h>
*/
struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue	*init(void)
{
	struct s_queue	*q;

	q = (struct s_queue*)malloc(sizeof(struct s_queue) * 1);
	q->first = NULL;
	q->last = NULL;
	return (q);
}

struct s_node	*init_node(void *content)
{
	struct s_node	*n;

	n = (struct s_node*)malloc(sizeof(struct s_node) * 1);
	n->content = content;
	n->next = NULL;
	return (n);
}

void	enqueue(struct s_queue *queue, void *content)
{
	struct s_node	*n;

	n = init_node(content);	
	if (queue->last == NULL)
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
	
	void			*ret;

	if (queue->first == NULL)
		return (NULL);
	ret = queue->first->content;
	if (queue->first->next == NULL)
	{
		queue->first = NULL;
		queue->last = NULL;
	}
	else
		queue->first = queue->first->next;
	return (ret);
}
	 
void	*peek(struct s_queue *queue)
{
	void			*ret;

	if (queue->first == NULL)
		return (NULL);
	ret = queue->first->content;
	return (ret);
}

int isEmpty(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (1);
	return (0);
}
/*
int		main(void)
{
	struct s_queue	*q;
	struct s_node	*n;

	q = init();
	printf("0x0 0x0:\t%p\t%p\n", q->first, q->last);
	n = init_node("Juan");
	printf("Juan:\t\t%s\n", n->content);
	enqueue(q, "Pedro");
	printf("Pedro\tPedro:\t%s\t%s\n", q->last->content, q->first->content);
	printf("& &:\t\t%p\t%p\n", q->first, q->last);
	printf("Pedro:\t\t%s\n", dequeue(q));
	printf("0x0 0x0:\t%p\t%p\n", q->first, q->last);
	enqueue(q, "Oscar");
	printf("Oscar:\t\t%s\n", peek(q));
	printf("0:\t\t%d\n", isEmpty(q));	
	printf("Oscar:\t\t%s\n", dequeue(q));
	printf("1:\t\t%d\n", isEmpty(q));	
	enqueue(q, "one");
	enqueue(q, "two");
	enqueue(q, "three");
	enqueue(q, "four");
	enqueue(q, "five");
	printf("one two three four five:\t%s %s %s %s %s \n", q->first->content,\
		 q->first->next->content, q->first->next->next->content,\
		 q->first->next->next->next->content, q->last->content);
	printf("one:\t\t%s\n", peek(q));
	printf("one:\t\t%s\n", dequeue(q));
	printf("two:\t\t%s\n", dequeue(q));
	printf("three:\t\t%s\n", dequeue(q));
	printf("four:\t\t%s\n", dequeue(q));
	printf("five:\t\t%s\n", dequeue(q));
	printf("1:\t\t%d\n", isEmpty(q));	
	return (0);
}
*/
