/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:10:05 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/17 14:20:12 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char	bit;
	int				i;

	i = 8;
	while (i--)	
	{
		bit = (octet >> i & 1) + 48;
		write(1, &bit, 1);
	}
}

int		main(void)
{
	print_bits(42);
	write(1, "\n", 1);
	return (0);
}
