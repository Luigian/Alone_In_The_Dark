/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 09:06:53 by exam              #+#    #+#             */
/*   Updated: 2019/08/06 10:04:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n < 10)
	{
		c = n + 48;
		write (1, &c, 1);
	}
	else if (n == 100)
		write (1, "100", 3);
	else
	{	
		c = (n / 10) + 48;
		write (1, &c, 1);
		c = (n % 10) + 48;
		write (1, &c, 1);
	}
}

int		main(void)
{
	int		n;

	n = 1;
	while (n < 101)
	{
		if (n % 3 == 0 && n % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (n % 3 == 0)
			write(1, "fizz", 4);
		else if (n % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(n);
		write(1, "\n", 1);
		++n;
	}
	return (0);
}
