/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:40:45 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/03 17:02:07 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	tab_swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	int					i;
	int					sw;
	unsigned int		csize;

	sw = 1;
	csize = size;
	while (sw)
	{
		i = 0;
		sw = 0;
		while (--size)
		{	
			if (tab[i] > tab[i + 1])
			{
				tab_swap(&tab[i], &tab[i + 1]);
				sw = 1;
			}
			++i;
		}
		size = csize;
	}
}

int		main(void)
{
	int		a[] = { 2147483647, 300, -1, -2147483648 };

	printf("%d\n", a[0]);
	printf("%d\n", a[1]);
	printf("%d\n", a[2]);
	printf("%d\n", a[3]);
	sort_int_tab(a, 4);
	printf("\n");
	printf("%d\n", a[0]);
	printf("%d\n", a[1]);
	printf("%d\n", a[2]);
	printf("%d\n", a[3]);
}
