/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:13:54 by lusanche          #+#    #+#             */
/*   Updated: 2019/08/19 21:38:49 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		brack(char *s)
{
	char	a[100];
	int		i;
	int		x;
	int		z;

	i = 0;
	x = 0;
	z = 0;
	while (z < 100)
		a[z++] = '0';
	while (s[i])
	{
		if (s[i] == '{' || s[i] == '(' || s[i] == '[')
		{
			if (a[x] != '0')
				++x;
			if (s[i] == '{')
				a[x] = '}';
			if (s[i] == '(')
				a[x] = ')';
			if (s[i] == '[')
				a[x] = ']';
		}
		else if (s[i] == '}' || s[i] == ')' || s[i] == ']')
		{
			if (s[i] == a[x])
			{
				a[x] = '0';
				if (x)
					--x;
			}
			else
				return (0);
		}
		++i;
	}
	if (a[0] == '0')
		return (1);
	else
		return (0);
}

int		main(int ac, char **av)
{
	int		i;
	
	i = 1;
	if (ac > 1)
	{
		--ac;
		while (ac--)
		{
			if (brack(av[i++]))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
		}
	}
	else
		write (1, "\n", 1);
	return (0);
}
