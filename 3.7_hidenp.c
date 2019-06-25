/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:23:22 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/17 16:57:29 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	hidenp(char *s1, char *s2)
{
	while (*s2 && *s1)
	{
		if (*s1 == *s2)
		{
			++s1;
			++s2;
		}
		else
			++s2;
	}
	if (*s1 == '\0')
		return ('1');
	else
		return ('0');
}

int		main(int ac, char **av)
{
	char		c;

	if (ac == 3)
	{
		c = hidenp(av[1], av[2]);
		write(1, &c, 1);
	}
	write(1, "\n", 1);
	return (0);
}
