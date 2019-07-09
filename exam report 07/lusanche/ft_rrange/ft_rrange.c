/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:51:55 by exam              #+#    #+#             */
/*   Updated: 2019/06/18 10:29:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int		*ret;
	int		*p;
	int		len;
	int		plus;

	len = 0;
	plus = 0;
	if (start > end)
	{
		len = start - end;
		plus = 1;
	}
	else if (start < end)
		len = end - start;
	else if (start == end)
		len = 0;
	++len;
	if (!(ret = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	p = ret;
	while (len--)
	{
		*p = end;
		if (plus)
			++end;
		else
			--end;
		++p;
	}
	return (ret);
}
