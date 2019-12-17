/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 12:33:39 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/24 15:48:37 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	search_and_replace(char *s1, char *s2, char *s3)
{
	int		i;
	
	i = 0;
	while (s1[i])
	{
		if (s1[i] == *s2)
			s1[i] = *s3;
		++i;
	}	
	write (1, s1, i); 
}

int		main(int ac, char **av)
{
	if (ac == 4 && !av[2][1] && !av[3][1])
		search_and_replace(av[1], av[2], av[3]);
	write (1, "\n", 1);
	return (0);
}
