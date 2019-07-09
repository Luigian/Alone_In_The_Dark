/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:26:40 by exam              #+#    #+#             */
/*   Updated: 2019/04/30 11:33:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	if (octet >= 128)
	{
		write(1, "1", 1);
		octet = octet - 128;
	}
	else
	{
		write(1, "0", 1);
	}
	if (octet >= 64)
	{
		write(1, "1", 1);
		octet = octet - 64;
	}
	else
	{
		write(1, "0", 1);
	}
	if (octet >= 32)
	{
		write(1, "1", 1);
		octet = octet - 32;
	}
	else
	{
		write(1, "0", 1);
	}
	if (octet >= 16)
	{
		write(1, "1", 1);
		octet = octet - 16;
	}
	else
	{
		write(1, "0", 1);
	}
	if (octet >= 8)
	{
		write(1, "1", 1);
		octet = octet - 8;
	}
	else
	{
		write(1, "0", 1);
	}
	if (octet >= 4)
	{
		write(1, "1", 1);
		octet = octet - 4;
	}
	else
	{
		write(1, "0", 1);
	}
	if (octet >= 2)
	{
		write(1, "1", 1);
		octet = octet - 2;
	}
	else
	{
		write(1, "0", 1);
	}
	if (octet == 1)
	{
		write(1, "1", 1);
	}
	else
	{
		write(1, "0", 1);
	}
}
