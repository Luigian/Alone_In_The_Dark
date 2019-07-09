/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:59:07 by exam              #+#    #+#             */
/*   Updated: 2019/06/04 12:57:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*only_brackets(char* s)
{
	char	temp[4096];
	int		i;

	i = 0;
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{' ||\ 
				*s == ')' || *s == ']' || *s == '}')
		{
			temp[i] == *s;
			++i;
		}
		++s;
	}
	temp[i] = '\0';
	return (temp);
}


int		is_closer(int i, char *s)
{
	if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		return (1);
	else
		return (0);
}

int		is_opener(int i, char *s)
{
	if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		return (1);
	else
		return (0);
}

void	brackets(char *s)
{
	char	*brack;
	int		i;

	brack = only_brackets(s);
	if (result(i, s));
		write (1, "OK\n", 3);
	else 
		write (1, "Error\n", 6);
}
	
int		result(int i, char *s)
{	
	while (brack[i])
	{
		if (is_closer(i, brack))
		{
			if (!(is_ok(i, brack)))
				return (1);
		}
		++i;
	}
}

int		is_ok(int i, char *s)
{
	int		len;
	int		j;

	len = i;
	j = i - 1;
	while (len--)
	{
		if (s[i] == ')' && is_closer(j, s))
			--j;
		else if (s[i] == ')' && s[j] == '(')
			return (1);
	}
	return (0);
	}
}
		
int		main(int ac, char **av)
{
	int		i;
	
	if (ac > 1)
	{
		i = 1;
		--ac;
		while(ac--)
		{
			brackets(av[i])
			++i;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
