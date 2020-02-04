/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:37:11 by exam              #+#    #+#             */
/*   Updated: 2020/02/04 12:57:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

int		gold_gain(int **mine, int n)
{
	int		max[n];
	int		c;
	int		i;
	int		x;
	int		y;
	int		ret;

	i = 0;
	while (i < n)
		max[i++] = 0;
	y = 0;
	c = 0;
	while (y < n)
	{
		if (mine[y][0] > max[0])
		{
			max[0] = mine[y][0];
			c = y;
		}
		++y;
	}
	x = 1;
	while (x < n)
	{
		i = c;
		y = i - 1;
		while (y < (i + 2) && y < n)
		{
			if (y >= 0)
			{	
				if (mine[y][x] > max[x])
				{
					max[x] = mine[y][x];
					c = y;
				}
			}
			++y;
		}
		++x;
	}
	ret = 0;
	i = 0;
	while (i < n)
		ret = ret + max[i++];
	return (ret);
}

/*
int		main(void)
{
	int		*mine[3];
  
	int		mine_0[] = {1, 0, 0};
	int		mine_1[] = {0, 3, 4};
	int		mine_2[] = {0, 0, 0};

	mine[0] = mine_0;
	mine[1] = mine_1;
	mine[2] = mine_2;

	printf("%d\n", gold_gain(mine, 3));
	return (0);
}
*/
