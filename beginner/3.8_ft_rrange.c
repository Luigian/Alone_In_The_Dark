/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:39:43 by exam              #+#    #+#             */
/*   Updated: 2019/10/21 21:24:10 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int		len;
	int		*result;
	int		dir;
	int		i;

	len = 0;
	dir = 0;
	i = 0;
	if (start > end)
	{
		len = start - end;
		dir = -1;
	}
	else if (end > start)
	{
		len = end - start;
		dir = 1;
	}
	++len;
	result = (int *)malloc(sizeof(int) * len);
	while (len--)
	{
		result[i] = end;
		end -= dir;
		++i;
	}
	return (result);
}

int		main(void)
{
	int		*a;
	
	a = ft_rrange(0, -3);
	printf("%d\t%d\t%d\t%d\t%d\n", a[0], a[1], a[2], a[3], a[4]);
	return (0);
}
