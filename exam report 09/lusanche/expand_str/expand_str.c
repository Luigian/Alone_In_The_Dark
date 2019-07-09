/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:14:33 by exam              #+#    #+#             */
/*   Updated: 2019/07/02 11:36:17 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	expand_str(char *s)
{
	int		word_found;
	
	word_found = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			++s;
		if (*s && *s != ' ' && *s != '\t')
			if (word_found)
				write (1, "   ", 3);
		while (*s && *s != ' ' && *s != '\t')
		{
			write (1, &(*s), 1);
			word_found = 1;
			++s;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		expand_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
