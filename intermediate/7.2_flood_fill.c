/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:19:05 by exam              #+#    #+#             */
/*   Updated: 2019/12/17 13:06:46 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <stdlib.h>
*/
typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	flood_solve(char target, char **tab, t_point size, t_point current)
{
	if (target == tab[current.y][current.x])
	{
		tab[current.y][current.x] = 'F';
		if (current.x + 1 < size.x)
		{
			current.x += 1;
			flood_solve(target, tab, size, current);
			current.x -= 1;
		}
		if (current.x > 0)
		{
			current.x -= 1;
			flood_solve(target, tab, size, current);
			current.x += 1;
		}
		if (current.y + 1 < size.y)
		{
			current.y += 1;
			flood_solve(target, tab, size, current);
			current.y -= 1;
		}
		if (current.y > 0)
		{
			current.y -= 1;
			flood_solve(target, tab, size, current);
			current.y += 1;
		}
	}
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	if (begin.x < size.x && begin.y < size.y)
	{
		target = tab[begin.y][begin.x];
		flood_solve(target, tab, size, begin);
	}
}
/*
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
}*/
