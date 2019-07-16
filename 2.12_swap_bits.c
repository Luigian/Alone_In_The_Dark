/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:14:26 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/15 20:34:41 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	int		four;
	int		column;
	unsigned char	bit;
	unsigned char	result;

	four = 4;
	column = 3;
	result = 0;
	while (four--)
	{
		bit = octet >> column & 1;
		result = (result * 2) + bit;
		--column;
	}
	four = 4;
	column = 7;
	while (four--)
	{
		bit = octet >> column & 1;
		result = (result * 2) + bit;
		--column;
	}
	return (result);
}

/* Option Two

unsigned char	swap_bits(unsigned char octet)
{	
	unsigned char	result;	
	int		column;
	int		four;
	unsigned char	bit;
	
	result = 0;
	column = 0;
	while (column != 3)
	{
		if (column == 0)
			column = 3;
		four = 4;
		while (four--)
		{
			bit = octet >> column & 1;
			printf("%d\n", bit);
			result = (result * 2) + bit;
			--column;
		}
		if (column == -1)
			column += 8;
	}
	return (result);
}
*/

int		main(void)
{
	char	c;

	c = '2';
	printf("%c\n", c);
	c = swap_bits(c);
	printf("%c\n", c);
	return (0);
}
