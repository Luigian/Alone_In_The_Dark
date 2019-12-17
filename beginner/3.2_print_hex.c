/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:45:50 by lusanche          #+#    #+#             */
/*   Updated: 2019/08/12 16:43:07 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_hex(unsigned int n)
{
	char	c;
	
	if (n >= 16)
		print_hex(n / 16);
	n = n % 16;
	c = n + (n > 9 ? 'a' - 10 : 48);
	write(1, &c, 1);
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
