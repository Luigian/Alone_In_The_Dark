/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:32:00 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/24 20:21:41 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_rrange(int start, int end)
{
	int		*a;
	int		len;
	int		i;
	int		sign;

	if (start > end)
	{
		len = start - end;
		sign = 1;
	}
	else if (start < end)
	{
		len = end - start;
		sign = -1;
	}
	else
		len = 0;
	len ++;
	if (!(a = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	i = 0;
	while (len--)
	{
		a[i] = end;
		++i;
		end += sign;
	}
	return (a);
}


int		main(void)
{
	int		*a;
	
	a = ft_rrange(0, -3);
	printf("%d\t%d\t%d\t%d\t%d\n", a[0], a[1], a[2], a[3], a[4]);
	return (0);
}

