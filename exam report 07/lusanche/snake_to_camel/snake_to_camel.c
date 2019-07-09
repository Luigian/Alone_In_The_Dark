/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:35:36 by exam              #+#    #+#             */
/*   Updated: 2019/06/18 09:48:44 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	snake_to_camel(char *s)
{
	int		up;
	char	c;

	up = 0;
	while (*s)
	{
		if (*s == '_')
		{
			up = 1;
			++s;
		}
		if (up)
		{
			c = *s - 32; 		
			write(1, &c, 1);
			up = 0;
		}
		else
			write(1, &(*s), 1);
		++s;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		snake_to_camel(av[1]);
	write(1,"\n", 1);
	return (0);
}
