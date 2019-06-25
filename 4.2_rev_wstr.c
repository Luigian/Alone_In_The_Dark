/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:22:28 by exam              #+#    #+#             */
/*   Updated: 2019/06/18 12:19:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_nw(char *s)
{
	int		counter;
	int		w;
	int		i;

	i = 0;
	w = 1;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t')
		{
			if (w)
			{
				++counter;
				w = 0;
			}
		}
		if (s[i] == ' ' || s[i] == '\t')
			w = 1;
		++i;
	}
	return (counter);
}
	
int		ft_nc(char *s)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
	{
		++counter;
		++i;
	}
	return (counter);
}

char	**rev_wstr(char *s)
{
	int		nw;
	char	**a;
	int		nc;
	int		x;
	int		y;

	nw = ft_nw(s);
	if (!(a = (char **)malloc(sizeof(char *) * nw + 1)))
		return (NULL);
	x = 0;
	while (nw--)
	{
		nc = ft_nc(s);
		if (!(a[x] = (char *)malloc(sizeof(char) * nc + 1)))
			return (NULL);
		y = 0;
		while (nc--)
		{
			a[x][y] = *s;
			++s;
			++y;
		}
		a[x][y] = '\0';
		++s;
		++x;
	}
	a[x] = NULL;
	return (a);
}

void	print_rev(char **a, int w)
{
	int		y;
	
	while (w--)
	{
		y = 0;
		while(a[w][y] != '\0')	
		{
			write(1, &(a[w][y]), 1);
			++y;
		}
		free (a[w]);
		if (w)
			write(1, " ", 1);
	}
}

int		main(int ac, char **av)
{
	char 	**array;
	int		nw;

	if (ac == 2)
	{
		nw = ft_nw(av[1]);
		array = rev_wstr(av[1]);
		print_rev(array, nw);
		free (array);
	}
	write(1, "\n", 1);
	return (0);
}
