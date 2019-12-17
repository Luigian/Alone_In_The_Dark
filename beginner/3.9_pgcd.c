/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:13:00 by exam              #+#    #+#             */
/*   Updated: 2019/08/12 12:13:57 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>

int		hcd(int a, int b)
{
	int		n;
	int		result;
	
	n = 1;
	result = 0;
	while (n <= a && n <= b)
	{
		if (a % n == 0 && b % n == 0)
			if (n > result)
				result = n;
		++n;
	}
	return (result);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%d\n", hcd(atoi(av[1]), atoi(av[2])));
	else
		printf("\n");
	return (0);
}
