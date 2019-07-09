/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:11:27 by exam              #+#    #+#             */
/*   Updated: 2019/06/18 09:32:53 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	search_and_replace(char *s1, char a, char b)
{
	while (*s1)
	{
		if (*s1 == a)
			write(1, &b, 1);
		else
			write(1, &(*s1), 1);
		++s1;
	}
}

int		main(int ac, char **av)
{
	if (ac == 4)
		if (!(av[2][1]) && (!(av[3][1])))			
			search_and_replace(av[1], *av[2], *av[3]);
	write(1, "\n", 1);
	return (0);
}   
