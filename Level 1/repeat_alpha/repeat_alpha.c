/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:17:46 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/17 14:06:50 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *s)
{
	int		n;
	
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
		{
			n = *s - 96;
			while (n--)
				write(1, &(*s), 1);			
		}
		else if (*s >= 'A' && *s <= 'Z')
		{
			n = *s - 64;
			while (n--)
				write(1, &(*s), 1);
		}
		else
			write(1, &(*s), 1);
		++s;
	}
}	

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		repeat_alpha(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
