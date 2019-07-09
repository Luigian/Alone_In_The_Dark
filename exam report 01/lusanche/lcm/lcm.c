/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:23:20 by exam              #+#    #+#             */
/*   Updated: 2019/05/07 11:25:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int i;
	int hcf;
	
	i = 1;
	hcf = 0;
	if (a == 0 || b == 0)
		return 0;
	while (i <= a && i <= b)
	{
		if (a % i == 0 && b % i == 0)
			if (i > hcf)
				hcf = i;
		i++;
	}
	return (a * b) / hcf;
}
