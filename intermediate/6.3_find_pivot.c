/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 09:02:41 by exam              #+#    #+#             */
/*   Updated: 2020/02/04 09:20:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

int		pv_total(int *arr, int n)
{
	int		total;
	int		i;

	total = 0;
	i = 0;
	while (i < n)
	{
		total = total + arr[i];
		++i;
	}
	return (total);
}

int		find_pivot(int *arr, int n)
{
	int		total;
	int		i;
	int		left;

	total = pv_total(arr, n);
	i = 0;
	left = 0;
	while (i < n)
	{
		left = left + arr[i];
		if ((total - left) == (left - arr[i]))
			return (i);
		++i;
	}
	return (-1);
}

/*
int		main(void)
{
	int		arr[] = {1, 2, 3, 4, 0, 6};
	int		arr[] = {-5, 10, 2, 5};
	int		arr[] = {1, 100, 0, 0, 1};
	int		arr[] = {7, 9, 8};
	int		arr[] = {1, 2};
	int		arr[] = {0, 0};

	printf("%d\n", find_pivot(arr, 2));
	return (0);
}
*/
