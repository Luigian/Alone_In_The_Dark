/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:20:56 by exam              #+#    #+#             */
/*   Updated: 2019/11/26 07:33:11 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

void	fill(char **tab, t_point size, t_point vector, char c)
{
	if (c == tab[vector.y][vector.x])
	{
		tab[vector.y][vector.x] = 'F';
		if (vector.x < size.x - 1)
		{
			++vector.x;
			fill(tab, size, vector, c);
			--vector.x;
		}
		if (vector.x > 0)
		{
			--vector.x;
			fill(tab, size, vector, c);
			++vector.x;
		}
		if (vector.y < size.y - 1)
		{
			++vector.y;
			fill(tab, size, vector, c);
			--vector.y;
		}
		if (vector.y > 0)
		{
			--vector.y;
			fill(tab, size, vector, c);
			++vector.y;
		}
	}
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;

	if (begin.y < size.y && begin.x < size.x)
	{
		c = tab[begin.y] [begin.x];
		fill(tab, size, begin, c);
	}
}

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
