/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 20:05:17 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/30 20:24:32 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int n)
{
	int		p;

	if (n == 1)
		printf("1");
	p = 2;
	while (n > 1)
	{
		while (n % p == 0)
		{
			printf("%d", p);
			n /= p;
			if (n > 1)
				printf("*");
		}
		++p;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
