/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:22:52 by exam              #+#    #+#             */
/*   Updated: 2019/10/22 12:43:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_digit(char c)
{
	return (c >= '0' && c <= '9');
}	

int		is_sign(char c)
{
	return (c == '+' || c == '-');
}	

int		is_operator(char c)
{
	return (c == '+' || c == '-' || c == '*'\
			|| c == '/' || c == '%');
}	

int		is_danger(char c)
{
	return (c == '/' || c == '%');
}	

int		do_op(int a, int b, char c)
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
	int		x;
	int		z;

	x = 0;
	z = 0;
	while (z < 499)
		a[z++] = 0;
	while (*s == ' ')
		++s;
	while (*s)
	{
		if ((is_digit(*s)) || (is_sign(*s) && is_digit(*(s + 1))))
		{
			a[x] = atoi(s);
			if (is_sign(*s))
				++s;
			while (is_digit(*s))
				++s;
			if (*s != ' ')
			{
				printf("Error\n");
				return (1);
			}
			while (*s == ' ')
				++s;
			++x;
		}
		else if (is_operator(*s))
		{
			if (x < 2 || (is_danger(*s) && a[x - 1] == 0))
			{
				printf("Error\n");
				return (1);
			}
			a[x - 2] = do_op(a[x - 2], a[x - 1], *s);
			++s;
			if (*s != ' ' && *s != '\0')
			{
				printf("Error\n");
				return (1);
			}
			while (*s == ' ')
				++s;
			x = x - 1;
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}
	if (x != 1)
	{
		printf("Error\n");
		return (1);
	}
	printf("%d\n", a[0]);
	return (0);
}

int		main(int ac, char **av)
{
	int		ret;
	
	ret = 0;
	if (ac == 2)
		ret = rpn_calc(av[1]);
	else
		printf("Error\n");
	return (0);
}
