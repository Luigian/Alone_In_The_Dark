/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:11:01 by exam              #+#    #+#             */
/*   Updated: 2019/12/24 15:08:37 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_words(char **split)
{
	int		i;
	int		j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			write(1, &(split[i][j]), 1);
			++j;
		}
		++i;
		if (split[i])
			write(1, " ", 1);
		else
			write(1, "\n", 1);
	}
}

int		count_words(char *s)
{
	int		ret;
	int		in;

	ret = 0;
	while (*s)
	{
		in	= 0;
		if (*s == ' ' || *s == '\t')
			++s;
		while (*s && *s != ' ' && *s != '\t')
		{
			if (!in)
			{
				++ret;
				in = 1;
			}
			++s;
		}
	}
	return (ret);
}

int		word_len(char *s)
{
	int		ret;

	ret = 0;
	while (*s == ' ' || *s == '\t')
		++s;
	while (*s && *s != ' ' && *s != '\t')
	{
		++ret;
		++s;
	}
	return (ret);
}

char	**ft_split(char *s)
{
	char	**ret;
	int		words;
	int		len;
	int		i;
	int		j;

	words = count_words(s);
	ret = (char **)malloc(sizeof(char *) * words + 1);
	i = 0;
	while (words--)
	{
		len = word_len(s);
		ret[i] = (char *)malloc(sizeof(char) * len + 1);
		while (*s == ' ' || *s == '\t')
			++s;
		j = 0;
		while (len--)
		{
			ret[i][j] = *s;
			++j;
			++s;
		}
		ret[i][j] = '\0';
		++i;
	}
	ret[i] = NULL;
	return (ret);
}

int		ord(char *s)
{
	char	 **split;

	split = ft_split(s);
	print_words(split);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ord(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
