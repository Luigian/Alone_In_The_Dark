/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 10:22:37 by exam              #+#    #+#             */
/*   Updated: 2019/05/28 11:08:45 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_iter(int a, int b)
{
	if (a > b)
		return (-1);
	else if (a < b)
		return (1);
	return (0);
}

int		ft_range_len(int a, int b, int i)
{
	int len;

	len = 0;
	if (a == b)
		return (1);
	while (a != b)
	{	
		a += i;
		++len;
	}
	return (len + 1);
}

int		*ft_range(int start, int end)
{
	int		*array;
	int 	i;
	int		iter;
	int		len;

	iter = ft_iter(start, end);
	len = ft_range_len(start, end, iter);
	if(!(array = (int *)malloc(sizeof(int) * len)))
			return (0);
	i = 0;
	while (len--)
	{
		array[i] = start;
		++i;	
		start += iter;
	}
	return (array);
}
