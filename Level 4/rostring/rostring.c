/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:34:24 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/03 13:06:35 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		count_words(char *s)
{
	int c;
	int count;

	count = 0;	
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			++s;
		c = 1;
		while (*s != ' ' && *s != '\t' && *s)
		{
			if (c)
				++count;
		   		c = 0;	
			++s;
		}
	}
	return (count);
}

int		word_len(char *s)
{
	int		len;
	
	len = 0;
	while (*s != ' ' && *s != '\t' && *s)
	{
		++s;
		++len;
	}
	return (len);
}

char	**ft_split(char *s)
{
	int		cw;
	int		wl;
	char	**ap;
	int		x;
	int		y;

	cw = count_words(s);
	if (!(ap = (char **)malloc(sizeof(char *) * cw + 1)))
		return (0);
	x = 0;
	while (cw--)
	{
		while (*s == ' ' || *s == '\t')
			++s;
		wl = word_len(s);
		if (!(ap[x] = (char *)malloc(sizeof(char) * wl + 1)))
			return (0);
		y = 0;
		while (wl--)
		{
			ap[x][y] = *s;
			++s;
			++y;
		}
		ap[x][y] = '\0';
		++x;
	}
	ap[x] = NULL;
	return (ap);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, &(*s), 1);
		++s;
	}
}

void	print_rostring(char **ap)
{
	int		i;
	
	i = 1;
	while (ap[i])
	{
		ft_putstr(ap[i]);
		write(1, " ", 1);
		++i;
	}
	ft_putstr(ap[0]);
}

int		main(int ac, char **av)
{
	char	**words;
		
	if (ac > 1 && *av[1])
	{
		words = ft_split(av[1]);
		print_rostring(words);
		free (words);
	}
	write(1, "\n", 1);
	return (0);
}

/*
int		main(void)
{
	printf("%d\n", count_words("    \t\t  hello my , good    friend    "));
	return (0);
}

int		main(void)
{
	printf("%d\n", word_len("hellowa"));
	return (0);
}
*/
