/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:42:48 by exam              #+#    #+#             */
/*   Updated: 2020/01/14 12:54:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	print_arr(int arr[], int n)
{
	int		i;

	i = 0;
	while (i < n)
		printf("[%d]", arr[i++]);
	printf("\n");
}


void	maxlenoc(int n, char **s)
{
	int		arr[n];
	int		i;
	int		small;
	int		index;

	i = 0;
	while (i < n)
	{
		arr[i] = strlen(s[i]);
		++i;
	}
	printf("lengths: ");
	print_arr(arr, n);
	i = 0;
	small = arr[i];
	index = 0;
	while (i < n)
	{
		if (arr[i] < small)
		{
			small = arr[i];
			index = i;
		}
		++i;
	}
	printf("small: [%d]\n", small);
	printf("index: [%d]\n", index);
	printf("string: %s\n", s[index]);


}


int		main(int ac, char **av)
{
	if (ac > 1)
		maxlenoc(--ac, ++av);
	else
		write(1, "\n", 1);
	return (0);
}

