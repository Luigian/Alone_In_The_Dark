#include <stdlib.h>
#include <stdio.h>

struct	s_node {
	void		*content;
	struct s_node	*next;
};

struct s_queue {
	struct s_node	*first;
	struct s_node	*last;
};

struct s_queue	*init(void)
{
	struct s_queue	*q;

	q = malloc(sizeof(struct s_queue));
	q->first = NULL;
	q->last = NULL;
	return (q);
}

void	enqueue(struct s_queue *queue, void *content)
{
	struct s_node	*n;

	n = malloc(sizeof(struct s_node));
	n->content = content;
	n->next = NULL;
	if (queue->last)
		queue->last->next = n;
	else
		queue->first = n;
	queue->last = n;
}

void	*peek(struct s_queue *queue)
{
	if (queue->first)
		return (queue->first->content);
	return (NULL);
}

void	*dequeue(struct s_queue *queue)
{
	void	*ret;

	ret = NULL;
	if (queue->first)
	{
		ret = queue->first->content;
		queue->first = queue->first->next;
		if (!queue->first)
			queue->last = NULL;
	}
	return (ret);
}	

int	isEmpty(struct s_queue *queue)
{
	if (queue->first)
		return (0);
	return (1);
}

int	main(void)
{
	struct s_queue	*q;

	q = init();
	printf("%p\n", q->first);
	enqueue(q, "monday");
	printf("%s\n", (char *)q->last->content); 
	printf("%s\n", (char *)peek(q)); 
	printf("%s\n", (char *)dequeue(q)); 
	printf("%d\n", isEmpty(q));
	return (0);
}
