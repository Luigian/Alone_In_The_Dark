/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:59:23 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/22 21:00:56 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int		*a;
	int		*beg;
	int		adv;
	int		len;

	adv = 0;
	len = 0;
	if (start > end)
	{
		len = (start - end);
		adv = -1;
	}
	else if (start < end)
	{
		len = (end - start);
		adv = 1;
	}
	++len;
	if (!(a = (int *)malloc(sizeof(int) * len)))
		return (0);
	beg = a;
	while (len--)
	{
		*a = start;
		start += adv;
		++a;
	}
	return (beg);
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

