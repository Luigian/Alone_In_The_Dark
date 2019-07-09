/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:19:17 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/30 17:54:16 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int		len;
	int		*a;

	len = (start >= end) ? (start - end) : (end - start);
	if (!(a = (int *)malloc(sizeof(int) * len + 1)))
		return (0);
	while (end != start)
	{
		*a = start;
		++a;
		(start > end) ? (start--) : (start++);
	}
	*a = start;
	return (a - len);
}

int		main(void)
{
	int		*nums;

	nums = ft_range(-3, 1);
	printf("%d\n", *nums);
	printf("%d\n", nums[0]);
	printf("%d\n", nums[1]);
	printf("%d\n", nums[2]);
	printf("%d\n", nums[3]);
	printf("%d\n", nums[4]);
	return (0);
}
