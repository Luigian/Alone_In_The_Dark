/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:53:31 by exam              #+#    #+#             */
/*   Updated: 2019/08/19 20:57:44 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
	int		n;

	i = 0;
	x = 0;
	z = 0;	
	while(z < 500)
		a[z++] = 0;
	while(s[i])
	{
		if (s[i] >= '0' && *s <= '9')
		{
			a[x] = atoi(&s[i]);
			++x;
			while (s[i] >= '0' && s[i] <= '9')
				++i;
			--i;
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*'\
				|| s[i] == '/' || s[i] == '%')
		{
			if (x == 1)
				write(1, "Error\n", 6);
			if ((s[i] == '/' || s[i] == '%') && a[x - 1] == 0)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			n = do_op(a[x - 2], s[i], a[x - 1]);
			a[x - 2] = n;
			x -= 1;	
		}
		++i;
	}
	if (x != 1)
		write(1, "Error\n", 6);
	else
		printf("%d\n", a[0]);
	return (0);
}

int		valid(char *s)
{
	int		i;
	int		numbers;
	int		signs;

	i = 0;
	numbers = 0;
	signs = 0;
	if (s[i] == '+' || s[i] == '-' || s[i] == '*'\
				|| s[i] == '/' || s[i] == '%')
		return (0);
	while (s[i])
	{
		if (s[i] >= '0' && *s <= '9')
		{
			++numbers;
			while (s[i] >= '0' && s[i] <= '9')
				++i;
			if (s[i] && s[i] != ' ')
				return (0);
			else if (s[i] && s[i] == ' ')
				++i;
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*'\
				|| s[i] == '/' || s[i] == '%')
		{
			++signs;
			++i;
			if (s[i] && s[i] != ' ')
				return (0);
			else if (s[i] && s[i] == ' ')
				++i;
		}
		else if (s[i] == ' ')
			++i;
		else 
			return (0);
	}
	if (numbers - signs != 1)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{	
		if (valid(av[1]))
			rpn_calc(av[1]);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
