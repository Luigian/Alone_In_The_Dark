/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:55:31 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/24 16:28:48 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	snake_to_camel(char *s)
{
	int		u;
	char	c;
	
	u = 0;
	while (*s)
	{
		if (*s == '_')
		{
			++s;
			u = 1;
		}
		if (u)
		{
			c = *s - 32;
			write (1, &c, 1);
			u = 0;
		}
		else
			write (1, &(*s), 1);
		++s;
	}
} 

int		main(int ac, char **av)
{
	if (ac == 2)
		snake_to_camel(av[1]);
	write (1, "\n", 1);
	return (0);
}
