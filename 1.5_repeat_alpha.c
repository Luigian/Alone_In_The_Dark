/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 09:08:05 by exam              #+#    #+#             */
/*   Updated: 2019/07/09 09:17:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *s)
{
	int		rep;
	char	c;

	while (*s)
	{
		c = *s;
		rep = 1;
		if (*s >= 'a' && *s <= 'z')
			rep = *s - 'a' + 1;
		else if (*s >= 'A' && *s <= 'Z')
			rep = *s - 'A' + 1;
		while (rep--)
			write(1, &c, 1);
		++s;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}
