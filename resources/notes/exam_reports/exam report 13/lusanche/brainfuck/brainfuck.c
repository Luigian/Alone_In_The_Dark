/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:55:35 by exam              #+#    #+#             */
/*   Updated: 2019/08/06 12:16:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		go_match(char *s, int i)
{
	int		bal;

	bal = 0;	
	if (s[i] == '[')
	{
		++i;
		while (s[i] != ']' || bal != 0)
		{
			if (s[i] == '[')
				++bal;
			else if (s[i] == ']')
				--bal;
			++i;
		}
	}
	else if (s[i] == ']')
	{
		--i;
		while (s[i] != '[' || bal != 0)
		{
			if (s[i] == ']')
				++bal;
			else if (s[i] == '[')
				--bal;
			--i;
		}
	}
	return (--i);
}

void	brainfuck(char *s)
{
	char	*a[2048];
	int		i;
	int		x;	
	int		z;

	i = 0;
	x = 0;
	z = 0;
	while (z < 2048)
		a[z++] = 0;
	while (s[i])
	{
		if (s[i] == '>')
			++x;
		else if (s[i] == '<')
			--x;
		else if (s[i] == '+')
			a[x]++;
		else if (s[i] == '-')
			a[x]--;
		else if (s[i] == '.')
			write (1, &a[x], 1);
		else if (s[i] == '[')
		{
			if (a[x] == 0)
				i = go_match(s, i);
		}
		else if (s[i] == ']')
		{
			if (a[x] != 0)
				i = go_match(s, i);
		}
		++i;
	}
}	

int		main(int ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
