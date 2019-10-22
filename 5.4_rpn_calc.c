/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:49:07 by exam              #+#    #+#             */
/*   Updated: 2019/10/15 12:50:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		do_op(int a, char c, int b)
{
	int		result;

	result = 0;
	if (c == '+')
		result = a + b;
	else if (c == '-')
		result = a - b;
	else if (c == '*')
		result = a * b;
	else if (c == '/')
		result = a / b;
	else if (c == '%')
		result = a % b;
	return (result);
}

int		rpn_calc(char *s)
{
	int		a[500];
	int		i;
	int		x;
	int		z;

	i = 0;
	x = 0;
	z = 0;
	
	while (z < 500)
	   a[z++] = '\0';
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			a[x] = atoi(s);
			++x;
			while (*s >= '0' && *s <= '9')
				++s;
			if (*s != ' ')
			{
				printf("Error\n");
				return (1);
			}
		}
		else if (*s == ' ')
		{
			while (*s == ' ')
				++s;
		}
		else if (*s == '+' || *s == '-' || *s == '*'\
				|| *s == '/' || *s == '%')
		{
			if (x < 2)
			{
				printf("Error\n");
				return (1);
			}
			if ((*s == '/' || *s == '%') && a[x - 1] == 0)
			{
				printf("Error\n");
				return (1);
			}
			a[x - 2] = do_op(a[x - 2], *s, a[x - 1]);
			x -= 1;
			++s;
		}
	}
	if (x != 1)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		printf("%d\n", a[0]);
		return (0);
	}
}

int		main(int ac, char **av)
{
	int		ret;

	ret = 0;
	if (ac == 2)
	{
		ret = rpn_calc(av[1]);
	}
	else
		printf("Error\n");
	return (0);
}
