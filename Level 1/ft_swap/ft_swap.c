/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:24:31 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/10 12:33:36 by lusanche         ###   ########.fr       */
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

int		main(void)
{
	int		i;
	int		j;
	int		*pi;
	int		*pj;

	i = 123;
	j = 456;
	pi = &i;
	pj = &j;
	printf("%d\t%d\n", *pi, *pj);
	ft_swap(pi, pj);
	printf("%d\t%d\n", *pi, *pj);
	return (0);
}
