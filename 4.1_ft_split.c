/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:49:45 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/15 18:15:20 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str)
{
	char **array;
	int x;
	int y;

	if (!(array = (char **)malloc(sizeof(char *) * 256)))
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	x = 0;
	while (*str)
	{
		if (!(array [x] = (char *)malloc(sizeof(char) * 4096)))
			return (0);
		y = 0;
		while (*str && *str != ' ' && *str != '\t' && *str != '\n')
		{
			array[x][y] = *str;
			++y;
			++str;
		}
		array[x][y] = '\0';
		++x;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
	array[x] = NULL;
	return (array);
}

int		main(void)
{
	char **arri;
		
	arri = ft_split("   \t\n hola  que\t  show    \n");
	printf("%s\n", arri[0]);
	printf("%s\n", arri[1]);
	printf("%s\n", arri[2]);
	printf("%s\n", arri[3]);
	return (0);
}
