/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:54:57 by exam              #+#    #+#             */
/*   Updated: 2019/06/25 12:56:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	start(char *s)
{
	while (*s != '[')
		--s;
}

void	end(char *s)
{
	while (*s != ']')
		++s;
}

int		*allocate(int n)
{
	int		*temp;
	int		i;

	if (!(temp = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	i = 0;
	while (n--)
	{
		temp[i] = 0;
		++i;
	}
	return (temp);
}

void	brainfuck(char *s)
{
	int		*a;

	a = allocate(2048);		
	while (*s)
	{
		if (*s == '[' && *a == 0)
			end(s);
		else if (*s == ']' && *a != 0)
			start(s);
		else 
		{
			if (*s == '+')
				*a += 1;
			if (*s == '-')
				*a -= 1;
			if (*s == '>')
				++a;
			if (*s == '<')
				--a;
			if (*s == '.')
				write(1, &*a, 1);
		}
		++s;
		printf("%d\n", *a);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	write (1, "\n", 1);
	return (0);
}
