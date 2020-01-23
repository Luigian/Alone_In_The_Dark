/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:30:38 by exam              #+#    #+#             */
/*   Updated: 2020/01/23 11:14:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	count_alpha(char *s)
{
	int		arr[128];
	int		i;
	int		p;

	i = 0;
	while (i < 128)
		arr[i++] = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
			arr[s[i] + 32] += 1; 
		else if (s[i] >= 97 && s[i] <= 122)
			arr[(int)s[i]] += 1;
		++i;
	}	
	i = 0;
	p = 0;
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90 && arr[s[i] + 32])
		{
			if (p)
				printf(", ");
			printf("%d%c", arr[s[i] + 32], s[i] + 32);
			p = 1;
			arr[s[i] + 32] = 0;
		}	
		else if (s[i] >= 97 && s[i] <= 122 && arr[(int)s[i]])
		{
			if (p)
				printf(", ");
			printf("%d%c", arr[(int)s[i]], s[i]);
			p = 1;
			arr[(int)s[i]] = 0;
		}
		++i;
	}
	printf("\n");
}

int		main(int ac, char **av)
{
	if (ac == 2)
		count_alpha(av[1]);
	else
		printf("\n");
	return (0);
}
