/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:45:50 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/13 13:06:48 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_hex(unsigned int n)
{
	if (n >= 16)
		print_hex(n / 16);
	n = n % 16;
	if (n < 10)
		n = n + 48;
	else
		n = (n + 'a') - 10;
	write(1, &n, 1);
}

int		main(int ac, char **av)
{
	int nb;
	
	if (ac == 2)
		if ((nb = atoi(av[1])) >= 0)
			print_hex(nb);
	write (1, "\n", 1);
	return (0);
}
