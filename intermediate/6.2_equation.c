/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:04:22 by exam              #+#    #+#             */
/*   Updated: 2020/01/14 10:29:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
#include <stdlib.h>
*/
/*
void	print_arr(int arr[])
{
	int		i;

	i = 0;
	while (i < 10)
		printf("[%d]", arr[i++]);
	printf("\n");
}
*/
void    equation(int n)
{
	int		a[] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99};
	int		cb[10] = {0};
	int		i;

	i = 0;
	while (i < 10)
	{
		cb[i] = n - a[i];
		++i;
	}
//	print_arr(a);
//	print_arr(cb);
//	printf("%d\n", n);
	i = 0;
	while (i < 10)
	{
		if (cb[i] >= 0 && cb[i] < 100)
		{
			printf("A = %d, B = %d, C = %d\n", i, cb[i] % 10, cb[i] < 10 ? 0 : cb[i] / 10);
		}	
		++i;
	}
}
/*
int		 main(int ac, char **av)
{
	if (ac == 2)
		equation(atoi(av[1]));
	return (0);
}*/
