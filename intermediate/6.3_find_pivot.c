/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 09:03:59 by exam              #+#    #+#             */
/*   Updated: 2020/01/23 10:23:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

int		fp_total(int *arr, int n)
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	while (i < n)
	{
		total = arr[i] + total;
		++i;
	}
	return (total);
}

int		find_pivot(int *arr, int n)
{
	int		total;
	int		left;
	int		i;

	total = fp_total(arr, n);
	left = 0;
	i = 0;
	while (i < n)
	{
		left = arr[i] + left;
		if ((total - left) == (left - arr[i]))
			return (i);
		++i;
	}
	return (-1);	
}

/*
int		main(void)
{
	int		arr[6] = {1, 2, 3, 4, 0, 6} ;
	int		n = 6;
	
	printf("%d\n", find_pivot(arr, n));
	return (0);
}
*/
