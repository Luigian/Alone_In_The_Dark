/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:32:38 by lusanche          #+#    #+#             */
/*   Updated: 2019/08/05 15:32:42 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		words_counter(char *s);
int		letters_counter(char *s);
char	**split(char *s, int words);
void	rev_print(char **array, int words);

int		main(int ac, char **av)
{
	char	**array;
	int		words;

	if (ac == 2)
	{
		words = words_counter(av[1]);
		array = split(av[1], words);
		rev_print(array, words);
	}
	write(1, "\n", 1);
	return (0);
}

void	rev_print(char **array, int words)
{
	while (words--)
	{
		write(1, array[words], letters_counter(array[words]));
		if (words)
			write(1, " ", 1);
		free(array[words]);
	}
	free(array);
}

char	**split(char *s, int words)
{
	int		x;
	int		y;
	int		letters;
	char	**array;

	if (!(array = (char **)malloc(sizeof(char *) * words + 1)))
		return (0);
	x = 0;
	while (words--)
	{
		letters = letters_counter(s);
		if (!(array[x] = (char *)malloc(sizeof(char) * letters + 1)))
			return (0);
		y = 0;
		while (letters--)
		{
			array[x][y] = *s;
			++y;
			++s;
		}
		array[x][y] = '\0';
		++x;
		++s;
	}
	array[x] = NULL;
	return (array);
}

int		words_counter(char *s)
{
	int		counter;
	int		w;

	counter = 0;
	w = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && !w)
		{
			++counter;
			w = 1;
		}
		else if ((*s == ' ' || *s == '\t') && w)
			w = 0;
		++s;
	}
	return (counter);
}

int		letters_counter(char *s)
{
	int		counter;

	counter = 0;
	while (*s == ' ' || *s == '\t')
		++s;
	while (*s != ' ' && *s != '\t' && *s != '\0')
	{
		++counter;
		++s;
	}
	return (counter);
}
