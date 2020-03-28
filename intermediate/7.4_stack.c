#include <stdlib.h>
#include <stdio.h>

struct s_node {
	void		*content;
	struct s_node	*next;
};

struct s_stack {
	struct s_node	*top;
};

struct s_stack	*init(void)
{
	struct s_stack	*s;

	s = malloc(sizeof(struct s_stack));
	s->top = NULL;
	return (s);
}

void	push(struct s_stack *stack, void *content)
{
	struct s_node	*n;

	n = malloc(sizeof(struct s_node));
	n->content = content;
	n->next = stack->top;
	stack->top = n;
}

void	*peek(struct s_stack *stack)
{
	if (stack->top != NULL)
		return (stack->top->content);
	return (NULL);
}

void	*pop(struct s_stack *stack)
{
	void	*ret;

	ret = NULL;
	if (stack->top != NULL)
	{
		ret = stack->top->content;
		stack->top = stack->top->next;
	}
	return (ret);
}			

int	isEmpty(struct s_stack *stack)
{
	if (stack->top != NULL)
		return (0);
	return (1);
}

int	main(void)
{
	struct s_stack	*s;

	s = init();
	printf("%p\n", s->top);
	push(s, "monday");
	printf("%p\n", s->top);
	printf("%s\n", (char *)s->top->content);
	printf("%s\n", (char *)peek(s));
	printf("%s\n", (char *)pop(s));
	printf("%d\n", isEmpty(s));
	printf("%p\n", s->top);
	return (0);
}
