/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:06:11 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 09:16:48 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat(char *s)
{
	int		rep;
	
	rep = 0;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
		{
			rep = *s - 96;
			while (rep--)
				write(1, &(*s), 1);
		}
		else if (*s >= 'A' && *s <= 'Z')
		{
			rep = *s - 64;
			while (rep--)
				write(1, &(*s), 1);
		}
		else
			write(1, &(*s), 1);
		++s;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		repeat(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
