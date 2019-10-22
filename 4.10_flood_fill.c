/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:41:24 by exam              #+#    #+#             */
/*   Updated: 2019/10/21 22:04:15 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

void	fill(char **tab, t_point size, t_point curr, char target)
{
	if (tab[curr.y][curr.x] == target)
	{
		tab[curr.y][curr.x] = 'F';
		if (curr.x != (size.x - 1))
		{
			curr.x = curr.x + 1;
			fill(tab, size, curr, target);
			curr.x = curr.x - 1;
		}
		if (curr.y != (size.y - 1))
		{
			curr.y = curr.y + 1;
			fill(tab, size, curr, target);
			curr.y = curr.y - 1;
		}
		if (curr.x != 0)
		{
			curr.x = curr.x - 1;
			fill(tab, size, curr, target);
			curr.x = curr.x + 1;
		}
		if (curr.y != 0)
		{
			curr.y = curr.y - 1;
			fill(tab, size, curr, target);
			curr.y = curr.y + 1;
		}
	}
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;
	
	target = tab[begin.y][begin.x];
	fill(tab, size, begin, target);
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
