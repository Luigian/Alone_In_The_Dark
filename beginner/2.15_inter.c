/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lusanche.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 09:24:46 by exam              #+#    #+#             */
/*   Updated: 2019/08/26 21:13:46 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		partner(int i, char *a, char *b)
{
	while (*b)
	{
		if (a[i] == *b)
			return (1);
		++b;
	}
	return (0);
}

int		first(int i, char *a)
{
	int		x;
	
	x = 0;
	while (x < i)
	{
		if (a[x] == a[i])
			return (0);
		++x;
	}
	return (1);
}

void	inter(char *a, char *b)
{
	int		i;

	i = 0;
	while (a[i])
	{
		if (first(i, a))
			if (partner(i, a, b))
				write(1, &a[i], 1);
		++i;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
