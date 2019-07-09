/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:12:08 by exam              #+#    #+#             */
/*   Updated: 2019/05/28 12:55:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_prime(int nb)
{
	int	i;

	i = 2;
	while (nb > i)
	{
		if (nb % i == 0)
			return (0);
		++i;
	}
	return (1);
}

void	fprime(char *s)
{
	int		n;
	int		prim;

	n = atoi(s);
	if (n == 1)
		printf("1");
	else
	{
		prim = 2;
		while (n > 1)
		{
			if (prim == n)
			{
				printf("%d", prim);
				break;
			}
			if (is_prime(prim))
				while (n > 1 && n % prim == 0)
				{
					printf("%d", prim);
					printf("*");
					n /= prim;
				}
			++prim;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(av[1]);
	printf("\n");
	return (0);
}
