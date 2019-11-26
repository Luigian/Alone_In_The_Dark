/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:26:58 by exam              #+#    #+#             */
/*   Updated: 2019/10/22 09:39:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (i < 8)
	{
		result = result * 2 + (octet >> i & 1);
		++i;
	}
	return ((unsigned char) result);
}

int		main(void)
{
	unsigned char c;

	c = '*';
	printf("%c\n", c);
	printf("%c\n", reverse_bits(c));
	return (0);
}