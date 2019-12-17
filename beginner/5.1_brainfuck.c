/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:53:36 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/22 19:19:10 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		go_match(char *s, int i)
{
	int 	bal;
	
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
	char	a[2048];
	int		i;
	int		x;
	int		z;

	i = 0;
	x = 0;
	z = 0;
	while (z < 2028)
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
			write(1, &a[x], 1);
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
	write(1, "\n", 1);
	return (0);
}
