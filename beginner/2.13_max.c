/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:30:05 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/29 18:31:04 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		max(int *tab, unsigned int len)
{
	int		i;
	int		bigger;

	if (len == 0)
		return (0);
	i = 0;
	bigger = 0;
	while (len--)
	{
		if (tab[i] > bigger)
			bigger = tab[i];
		++i;
	}
	return (bigger);
}

int		main(void)
{
	int		tab[] = {3, 656, 78, 99};

		printf("%d\n", max(tab, 4));
	return (0);
}
