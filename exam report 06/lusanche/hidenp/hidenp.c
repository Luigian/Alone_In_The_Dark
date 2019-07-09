/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:26:23 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 09:38:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	hiden(char *s1, char *s2)
{
	if (!s1)
		return('1');
	while (*s2)
	{
		if (*s1 == *s2)
		{
			++s1;
			++s2;
		}
		else
			++s2;
	}
	if (!*s1)
		return ('1');
	else 
		return ('0');
}

int		main(int ac, char **av)
{
	char	result;
	
	if (ac == 3)
	{
		result = hiden(av[1], av[2]);
		write (1, &result, 1);
	}
	write(1, "\n", 1);
	return (0);
}
