/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:53:12 by exam              #+#    #+#             */
/*   Updated: 2019/07/15 20:54:11 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	int		*a;
	int		*b;
	int		size_c;

	a = tab;
	--size;
	while (size)
	{
		b = a + 1;
		size_c = size;
		while (size_c--)
		{
			if (*a > *b)
				ft_swap(a , b);
			++b;
		}
		--size;
		++a;
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
