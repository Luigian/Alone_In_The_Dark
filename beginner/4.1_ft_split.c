/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:27:26 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/11 18:17:30 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		letter_count(char *s)
{
	int		result;
	int		i;
	
	result = 0;
	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		++i;
	while (s[i] != '\t' && s[i] != '\n' && s[i] != ' ' && s[i] != '\0')
	{
		++result;
		++i;
	}
	return (result);
}

int		word_count(char *s)
{
	int		i;
	int		p;
	int		result;

	i = 0;
	p = 1;
	result = 0;
	while (s[i])
	{	
		if (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
			p = 1;
		else 
		{
			if (p)
			{
				++result;
				p = 0;
			}
		}
		++i;
	}
	return (result);
}

char	**ft_split(char *s)
{
	char	**str;
	int		w;
	int		x;
	int		l;
	int		y;

	w = word_count(s);
	printf("%d\n", w);
	if (!(str = (char **)malloc(sizeof(char *) * w + 1)))
		return (NULL);
	x = 0;
	while (w--)
	{
		l = letter_count(s);
		printf("%d\n", l);
		if (!(str[x] = (char *)malloc(sizeof(char) * l + 1)))
			return (NULL);
		while (*s == '\t' || *s == '\n' || *s == ' ')
			++s;
		y = 0;
		while (l--)
		{
			str[x][y] = *s;
			++s;
			++y;
		}
		str[x][y] = '\0';
		++x;
	}
	str[x] = NULL;
	return (str);	
}

int		main(void)
{
	char	**str;
	
	str = ft_split("  \t\n test  \t\n number  \n hi");
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	printf("%s\n", str[3]);
	return (0);
}
