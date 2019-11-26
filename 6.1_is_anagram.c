/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 09:02:31 by exam              #+#    #+#             */
/*   Updated: 2019/11/26 09:14:10 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int		is_anagram(char *a, char *b)
{
	int		array[128] = {0};
	int		i;

	while (*a)
	{
		array[(int)*a] += 1;
		++a;
	}
	while (*b)
	{
		array[(int)*b] -= 1;
		++b;
	}
	i = 0;
	while (i < 128)
	{
		if (array[i++])
			return (0);
	}
	return (1);
}
/*
int		main(void)
{
	printf("%d\n", is_anagram("cinema", "iceman"));
	return (0);
}
*/
