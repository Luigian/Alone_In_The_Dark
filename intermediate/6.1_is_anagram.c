/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:02:12 by exam              #+#    #+#             */
/*   Updated: 2019/12/17 13:04:05 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
void	print_a(int a[])
{
	int i;

	i	= 0;
	while (i < 128)
		printf("%d", a[i++]);
	printf("\n");
}
*/
int		is_anagram(char *a, char *b)
{
	int		arr[128] = {0};
	int		i;

//	print_a(arr);
	while (*a)
	{
		arr[(int)*a] += 1;
		++a;
	}
//	print_a(arr);
	while (*b)
	{
		arr[(int)*b] -= 1;
		++b;
	}
//	print_a(arr);
	i = 0;
	while (i < 128)
	{
		if (arr[i++])
			return (0);
	}
	return (1);
}

int		main(void)
{
	printf("%d\n", is_anagram("cinema", "iceman"));
	return (0);
}
