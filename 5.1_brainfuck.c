/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:03:24 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/12 09:21:26 by lusanche         ###   ########.fr       */
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

void	brainiak(char *s)
{
	char	a[4096];
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	while (z < 4096)
		a[z++] = 0;
	while (s[i])
	{
		if (s[i] == '>')
			++j;
		else if (s[i] == '<')
			--j;
		else if (s[i] == '+')
			a[j]++;
		else if (s[i] == '-')
			a[j]--;		
		else if (s[i] == '.')
			write(1, &a[j], 1);
		else if (s[i] == '[')
		{
			if (a[j] == 0)
				i = go_match(s, i);
		}
		else if (s[i] == ']')
		{
			if (a[j] != 0)
				i = go_match(s, i);
		}
		++i;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		brainiak(av[1]);
	write(1, "\n", 1);
	return (0);
}
