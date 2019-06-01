/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:41:33 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/30 17:09:13 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	expand_str(char *s)
{
	int		sp;

	sp = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			++s;
		if (*s && sp)
			write(1, "   ", 3);
		while (*s != ' ' && *s != '\t' && *s)
		{
			write(1, &(*s), 1);
			++s;
			sp = 1;
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
