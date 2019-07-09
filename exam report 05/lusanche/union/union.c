/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:19:03 by exam              #+#    #+#             */
/*   Updated: 2019/06/04 10:12:36 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_concat(char *a, char *b)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (a[i])
		++i;
	while (b[j])
	{
		a[i] = b[j];
		++i;
		++j;
	}
	a[i] = b[j];
	return (a);
}

int		is_first(int i, char *s)
{
	int		len;
	int		j;

	if (i == 0)
		return (1);
	else
	{
		len = i;
		j = 0;
		while (len--)
		{
			if (s[i] != s[j])
				++j;
			else
				return (0);
		}
		return (1);
	}
}

void	ft_union(char *a, char *b)
{
	char	*c;
	int		i;
	
	c = ft_concat(a, b);
	i = 0;
	while (c[i])
	{
		if (is_first(i, c))
		{
			write(1, &(c[i]), 1);
		}
		++i;
	}	
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_union(av[1], av[2]);
	}
	write (1, "\n", 1);
	return (0);
}
