/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:02:55 by exam              #+#    #+#             */
/*   Updated: 2019/11/12 09:07:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		aff_a(char *s)
{
	while (*s)
	{
		if (*s == 'a')
		{
			write(1, "a\n", 2);
			return (0);
		}
		++s;
	}
	write(1, "\n", 1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		aff_a(av[1]);
	else
		write(1, "a\n", 2);
	return (0);
}
