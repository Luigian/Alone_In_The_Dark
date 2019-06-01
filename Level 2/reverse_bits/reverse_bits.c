/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:30:13 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/27 20:09:49 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int		j;
	int		bit;
	int 	i;
	int		result;

	j = 8;
	i = 0;
	result = 0;
	while (j--)
	{
		bit = octet >> i & 1;
		result = (result * 2) + bit;
		++i;
	}
	return ((unsigned char)result);
}


int		main(void)
{
	unsigned char c;

	c = '*';
	printf("%c\n", c);
	c = reverse_bits(c);
	printf("%c\n", c);
	return (0);
}

