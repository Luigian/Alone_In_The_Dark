/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:39:44 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/10 13:52:14 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_cat(char *s1, char *s2)
{
	int		i;
	
	i = 0;
	while (s1[i])
		i++;
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = *s2;
	return (s1);
}

int		is_first(char *s, int ind)
{
	int		i;
	
	i = 0;
	while (i != ind)
	{
		if (s[i] != s[ind])
			++i;
		else
			return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		i;
	
	if (ac-- == 3)
	{
		ft_cat(av[1], av[2]);
		i = 0;
		++av;
		while ((*av)[i])
		{
			if (is_first(*av, i))
				write(1, &((*av)[i]), 1);
			++i;
		}
	}
	write(1, "\n", 1);
	return (0);
}
