/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:06:59 by exam              #+#    #+#             */
/*   Updated: 2019/11/19 11:32:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WARNING : THIS EXERCISE HAVE SOME ERRORS


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

struct s_queue *init(void)
{
	struct s_queue		*cola;

	cola = (struct s_queue *)malloc(sizeof(struct s_queue) * 1);
	cola->first = NULL;
	cola->last = NULL;
	return (cola);
}

/*
struct s_node *init_item(void)
{
	struct s_node		*item;

	item = (struct s_node *)malloc(sizeof(struct s_node) * 1);
	item->content = "holaaa";
	item->next = NULL;
	return (item);
}
*/

void	enqueue(struct s_queue *queue, void *content)
{
	if (queue->last == NULL)
	{
		queue->first = content;
		queue->last = content;
	}
	else
	{
		queue->last->next = content;
		queue->last = content;
	}
}

void	*dequeue(struct s_queue *queue)
{
	struct s_node		*temp;
	
	if (queue->first == NULL)
		return (NULL);
	else
	{
		temp = queue->first;
		if (queue->first->next == NULL)
			queue->last = NULL;
		queue->first = queue->first->next;
		temp->next = NULL;
	}
	return (temp);
}

void	*peek(struct s_queue *queue)
{
	struct s_node		*temp;
	
	if (queue->first == NULL)
		return (NULL);
	else
		temp = queue->first;
	return (temp);
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
	struct s_queue		*cola;
	struct s_node		*item;
	struct s_node		*new;
	struct s_node		*beg;

	cola = init();
	printf("%p\n", (void *)cola->last);
	item = init_item();
	enqueue(cola, item);
	printf("%p\n", (void *)cola->last);
	printf("%s\n", cola->last->content);
	new = dequeue(cola);
	printf("%p\n", (void *)cola->last);
	printf("%p\n", (void *)new);
	printf("%s\n", new->content);
	beg = peek(cola);
	printf("%p\n", (void *)beg);
	printf("%d\n", isEmpty(cola));
	return (0);
}*/
