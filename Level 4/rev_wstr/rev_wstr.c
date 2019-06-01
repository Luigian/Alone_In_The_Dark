/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 21:49:30 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/29 23:16:41 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_count_words(char *s)
{
	int words;
	int w;

	words = 0;
	while (*s)
	{
		w = 1;
		while (*s != ' ' && *s != '\t' && *s)
		{
			if (w)
				++words;
			w = 0;
			++s;
		}
		while (*s == ' ' || *s == '\t')
			++s;
	}
	return (words);
}

int		ft_word_len(char *s)
{
	int		count;
	
	count = 0;
	while (*s != ' ' && *s != '\t' && *s != '\0')
	{
		++s;
		++count;
	}
	return (count);
}

char	**create_bidimensional_array(char *str)
{
	char	**biarr;
	int		cw;
	int		wl;
	int 	x;
	int 	y;

	cw = ft_count_words(str);
	if (!(biarr = (char **)malloc(sizeof(char *) * cw + 1)))
		return (0);
	x = 0;
	while (cw--)
	{
		wl = ft_word_len(str);
		if (!(biarr[x] = (char *)malloc(sizeof(char ) * wl + 1)))
			return (0);
		y = 0;
		while (wl--)
		{
			biarr[x][y] = *str;
			++y;
			++str;
		}
		biarr[x][y] = '\0';
		++x;
		while (*str == ' ' || *str == '\t')
			++str;
	}
	biarr[x] = NULL;
	return (biarr);
}

void	biarray_rev_print(char **s)
{
	int		i;
	int		j;
	int		count;
	char	c;
	

	i = 0;
	count = 0;
	while (s[i])
	{
		++i;
		++count;
	}
	--i;
	while (count--)
	{
		j = 0;
		while (s[i][j])
		{
			c = s[i][j];
			write(1, &c, 1);
			++j;
		}
		if (count)
			write(1, " ", 1);
		free (s[i]);
		--i;
	}
	free (s);
}

int		main(int ac, char **av)
{
	char	**temp;
		
	if (ac == 2)
	{
		temp = create_bidimensional_array(av[1]);
		biarray_rev_print(temp);
	}
	write(1, "\n", 1);
	return (0);
}

/*
int		main(void)
{
	printf("%d\n", ft_count_words("fgsfd dfgdfs fdgdfs sdfg"));
	printf("%d\n", ft_word_len("fghsfd dfgdfs fdgdfs sdfg"));
	return (0);
}
*/
