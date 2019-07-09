/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:03:57 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/10 15:44:36 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	expand(char *s)
{
	int		sp;
	
	sp = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			++s;
		if (*s && sp)
			write(1, "   ", 3);
		while (*s && *s != ' ' && *s != '\t')
		{
			write(1, &(*s), 1);
			sp = 1;
			++s;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		expand(av[1]);
	write (1, "\n", 1);
	return (0);
}
