/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:24:39 by exam              #+#    #+#             */
/*   Updated: 2019/05/21 10:58:54 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		int n;
		int i;
		int x;
		
		i = 2;
		
		n = atoi(av[1]);
		
		
		while (i < n)
		
			if (ft_isprime(i))
				while (n % i == 0)
				{
					printf("%d", i);
					n = n / i;
				}
			++i;
		
		
			
			

			


			
			
int		ft_isprime(int i)
{	
		int x;
		
		x = 2;
		while (i > x)
		{
			if (i % x != 0)	
				++x;
			else
				return (0);
		}
		return (1);
}
		



			














	}
	write (1, "\n", 1);
	return (0);
}
