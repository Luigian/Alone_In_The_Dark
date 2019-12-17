/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 09:09:55 by exam              #+#    #+#             */
/*   Updated: 2019/08/19 19:56:54 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *s)
{
	int		n;

	while (*s)
	{
		n = 1;
		if (*s >= 'a' && *s <= 'z')
			n = *s - 'a' + 1;
		else if (*s >= 'A' && *s <= 'Z')
			n = *s - 'A' + 1;
		while(n--)
			write(1, s, 1);
		++s;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}
