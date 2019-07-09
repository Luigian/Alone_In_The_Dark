/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:16:45 by exam              #+#    #+#             */
/*   Updated: 2019/05/14 12:58:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		char **array;
		int x;
		int y;

		if (!(array = (char **)malloc(sizeof(char *) * 256)))
			return (0);
		x = 0;
		while (*av[1])
		{
			if (!(array[x] = (char *)malloc(sizeof(char) * 4096)))
				return (0);
			y = 0;
			while(*av[1] != ' ' && *av[1] != '\t' && *av[1])
			{
				array[x][y] = *av[1];
				++y;
				++av[1];
			}
			array[x][y] = '\0';
			++x;
			while (*av[1] == ' ' || *av[1] == '\t')
				++av[1];
		}
		--x;
		do
		{
			y = 0;
			while (array[x][y] != '\0')
			{
				write(1, &(array[x][y]), 1);
				++y;
			}
			if (x > 0)
				write(1, " ", 1);
			--x;
		}
		while (x + 1);
		free(array);
	}
	write(1, "\n", 1);
	return (0);
}





