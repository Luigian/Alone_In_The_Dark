/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:29:52 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/30 16:00:09 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	alpha_mirror(char *s)
{
	char	c;

	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			c = ('z' - *s) + 'a';
		else if (*s >= 'A' && *s <= 'Z')
			c = ('Z' - *s) + 'A';
		else
			c = *s;
		write(1, &c, 1);
		++s;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		alpha_mirror(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
