/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:25:42 by exam              #+#    #+#             */
/*   Updated: 2019/07/15 20:47:00 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int		p;
	unsigned int		hcf;
	
	if (a == 0 || b == 0)
		return (0);
	p = 2;
	hcf = 1;
	while (p <= a && p <= b)
	{
		if (a % p == 0 && b % p == 0)
			if (p > hcf)
				hcf = p;
		++p;
	}
	return ((a * b) / hcf);
}

int		main(void)
{
	printf("%d\n", lcm(60, 40));
	return (0);
}
