/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:37:10 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 10:24:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		c;
	
	if (nb >= 10)
		ft_putnbr(nb / 10);
	nb = nb % 10;
	c = nb + 48;
	write (1, &c, 1);
}

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

int		ft_atoi(char *s)
{
	int		n;
	
	n = 0;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		n = (n * 10) + (*s - 48);
		++s;
	}
	return (n);
}

void	tab_mult(char *s)
{
	int		n;
	char	c;	

	n = ft_atoi(s);
	if (n * 9 <= 2147483647)
	{
		c = '1';
		while (c <= '9')
		{
			write(1, &c, 1);
			write(1, " x ", 3);
			ft_putstr(s);
			write(1, " = ", 3);
			ft_putnbr((c - 48) * n);
			write(1, "\n", 1);
			c = c + 1;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		tab_mult(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
