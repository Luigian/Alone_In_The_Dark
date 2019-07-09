/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 09:16:03 by exam              #+#    #+#             */
/*   Updated: 2019/05/28 09:48:21 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	alpha_mirror(char c)
{
	if (c >= 'a' && c <= 'z')
		c = ('z' - c) + 'a';
	else if (c >= 'A' && c <= 'Z')
		c = ('Z' - c) + 'A';
	return (c);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		char a;

		while (*av[1])
		{
			a = alpha_mirror(*av[1]);
			write(1, &a, 1);
			++av[1];
		}
	}
	write (1, "\n", 1);
	return (0);
}
