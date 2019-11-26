/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:04:04 by exam              #+#    #+#             */
/*   Updated: 2019/11/26 08:16:45 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_anagram(char *a, char *b)
{
	int		arr[127];
	int		i;

	i = 0;
	while (i < 127)
		arr[i++] = 0;
	while (*a)
	{
		arr[(int)*a] += 1;
		++a;
	}
	while (*b)
	{
		arr[(int)*b] -= 1;
		++b;
	}
	i = 32;
	while (i < 127)
	{
		if (arr[i++])
			return (0);
	}
	return (1);
}

int	main(void)
{
	printf("%d\n", is_anagram("cinema", "iceman"));
	return (0);
}
