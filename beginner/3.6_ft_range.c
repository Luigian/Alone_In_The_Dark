/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:55:31 by exam              #+#    #+#             */
/*   Updated: 2019/11/12 10:15:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int		dir;
	int		len;
	int		*arr;
	int		i;
	
	len = 1;
	dir = 0;
	if (start > end)
	{
		len += start - end;
		dir = -1;
	}
	else if (end > start)
	{
		len += end - start;
		dir = 1;
	}
	arr = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (len--)
	{
		arr[i] = start;
		start += dir;
		++i;
	}
	return (arr);
}

int		main(void)
{
	int		*nums;

	nums = ft_range(-3, 1);
	printf("%d\n", nums[0]);
	printf("%d\n", nums[1]);
	printf("%d\n", nums[2]);
	printf("%d\n", nums[3]);
	printf("%d\n", nums[4]);
	return (0);
}