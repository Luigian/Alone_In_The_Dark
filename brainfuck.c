/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:15:45 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/03 23:08:24 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*create_array(void)
{
	char	*a;
	int		len;
	int		i;

	len = 2048;
	i = 0;
	if (!(a = (char *)malloc(sizeof(char) * len)))
		return (0);	
	while (len--)
	{
		a[i] = 0;
		++i;
	}
	return (a);
}

char	*to_end(char *s)
{
	while (*s != ']' && *s)
		++s;
	return (s);
}	

char	*to_start(char *s)
{
	while (*s != '[' && *s)
		--s;
	--s;
	return (s);
}

void	brainfuck(char *s)
{
	char	*a;
	char	*beg;
		
	a = create_array();
	beg = a;
	while (*s)
	{
		if (*s == '>')
			++a;
		else if (*s == '<')
			--a;
		else if (*s == '+')
			*a += 1;
		else if (*s == '-')
			*a -= 1;
		else if (*s == '.')
			write (1, &(*a), 1);
		else if (*s == '[')
		{
			if (*a == 0)
			{
				s = to_end(s);
			}
		}
		else if (*s == ']')
		{
			s = to_start(s);
		}
		++s;
	}
	free (beg);
}

int		main(int ac, char **av)
{
	if (ac > 1 && av[1])
	{
		brainfuck(av[1]);
	}
	else
		write (1, "\n", 1);
	return (0);
}
