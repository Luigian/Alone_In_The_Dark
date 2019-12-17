/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:24:03 by exam              #+#    #+#             */
/*   Updated: 2019/11/12 09:49:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_lastword(char *s)
{
	while (*s && (*s != ' ' && *s != '\t'))
		++s;
	while (*s == ' ' || *s == '\t')
			++s;
	if (*s == '\0')
		return (1);
	return (0);
}

int		last_word(char *s)
{
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			++s;
		if (*s == '\0')
			return (0);
		else if (is_lastword(s))
		{
			while (*s && (*s != ' ' && *s != '\t'))
			{
				write(1, s, 1);
				++s;
			}
			return (0);
		}
		else
		{
			while (*s && (*s != ' ' && *s != '\t'))
				++s;
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}
