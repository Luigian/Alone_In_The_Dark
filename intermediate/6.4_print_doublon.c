/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 09:03:09 by exam              #+#    #+#             */
/*   Updated: 2020/03/10 09:33:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int		i;
	int		j;
	int		x;
	
	i = 0;
	j = 0;
	x = 0;
	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			if (x)
				printf(" ");
			printf("%d", a[i]);
			x = 1;
			++i;
			++j;
		}
		else if (a[i] < b[j])
			++i;
		else if (b[j] < a[i])
			++j;
	}
	printf("\n");
}

/*
int		main(void)
{
//	int		a[] = {1, 2, 10, 15};
//	int		b[] = {2, 20, 40, 70};
//	int		na = 4;
//	int		nb = 4;
//	int		a[] = {-5, 2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
//	int		b[] = {2, 4, 5, 6, 7, 10, 40, 70};
//	int		na = 11;
//	int		nb = 8;
	int		a[] = {100, 200, 300};
	int		b[] = {1, 2, 3, 4};
	int		na = 3;
	int		nb = 4;

	print_doublon(a, na, b, nb);
	return (0);
}
*/
