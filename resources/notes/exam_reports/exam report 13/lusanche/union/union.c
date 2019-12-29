/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:09:23 by exam              #+#    #+#             */
/*   Updated: 2019/08/06 11:08:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		single(char *c, char l)
{
	int		i;

	i = 0;
	while (c[i])
	{
		if (c[i] == l)
			return (0);
		++i;
	}
	return (1);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_union(char *a, char *b)
{
	char	c[500];
	int		i;

	i = 0;
	c[499] = '\0';
	while (*a)
	{
		if (single(c, *a))
		{
			c[i] = *a;
			++i;
		}
		++a;
	}
	while (*b)
	{
		if (single(c, *b))
		{
			c[i] = *b;
			++i;
		}
		++b;
	}
	c[i] = '\0';
	ft_putstr(c);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
