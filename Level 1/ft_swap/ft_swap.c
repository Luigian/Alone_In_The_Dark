/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:28:15 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/09 13:40:46 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		main(void)
{
	int i;
	int j;
	int *p1;
	int *p2;
	
	
	i = 123;
	j = 456;
	p1 = &i;
	p2 = &j;
	printf("%d\t%d\n", *p1, *p2);
	ft_swap(p1, p2);
	printf("%d\t%d\n", *p1, *p2);
	return (0);
}
