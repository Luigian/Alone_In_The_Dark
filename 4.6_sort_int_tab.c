/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:40:33 by exam              #+#    #+#             */
/*   Updated: 2019/07/08 22:06:33 by lusanche         ###   ########.fr       */
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
	int		*first;
	int		*second;
	int		size_c;

	first = tab;
	--size;
	while (size)
	{
		size_c = size;
		second = first + 1;
		while (size_c--)
		{
			if (*first > *second)
				ft_swap(&(*first), &(*second));
			++second;
		}
		++first;
		--size;
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
