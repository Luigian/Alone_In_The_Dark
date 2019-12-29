/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:36:21 by exam              #+#    #+#             */
/*   Updated: 2019/08/06 11:50:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int n)
{
	int		p;

	if (n == 1)
		printf("1");
	else
	{
		p = 2;
		while (n > 1)
		{
			while (n % p == 0)
			{	
				printf("%d", p);
				n = n / p;
				if (n > 1)
					printf("*");
			}
			++p;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
