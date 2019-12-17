/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:21:00 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/01 17:40:10 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	camel_to_snake(char *s)
{
	char	c;
	
	while (*s)
	{
		c = *s;
		if (*s >= 'A' && *s <= 'Z')
		{
			write(1, "_", 1);
			c = *s + 32;
		}
		write(1, &c, 1);
		++s;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		camel_to_snake(av[1]);
	write(1, "\n", 1);
	return (0);
}
