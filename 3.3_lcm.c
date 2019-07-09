/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:08:10 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/13 13:16:07 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int i;
	unsigned int hcf;
	
	if (a == 0 || b == 0)
		return (0);
	i = 1;
	hcf = 0;
	while (i <= a && i <= b)
	{
		if (a % i == 0 && b % i == 0)
			if (i > hcf)
				hcf = i;
		++i;
	}
	return ((a * b) / hcf);
}

int		main(void)
{
	printf("%d\n", lcm(0, 20));
	return (0);
}

