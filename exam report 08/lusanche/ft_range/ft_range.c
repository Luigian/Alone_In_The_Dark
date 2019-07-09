/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 09:36:46 by exam              #+#    #+#             */
/*   Updated: 2019/06/25 09:54:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int		len;
	int		*a;
	int		sign;
	int		i;

	len = 0;
	if (start > end)
	{
		len = start - end;
   		sign = -1;	
	}
	else if (start < end)
	{
		len = end - start;
   		sign = 1;	
	}
	else if (start == end)
		len = 0;
	++len;
	if (!(a = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	i = 0;
	while (len--)
	{
		a[i] = start;
		start += sign;
		++i;
	}
	return (a);
}
