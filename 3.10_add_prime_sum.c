/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 09:38:58 by exam              #+#    #+#             */
/*   Updated: 2019/08/19 20:17:15 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;
	
	if (n >= 10)
		ft_putnbr(n / 10);
	n = n % 10;
	c = n + 48;
	write(1, &c, 1);
}	

int		prime(int n)
{
	int		i;

	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		++i;
	}
	return (1);
}

void	print_primes(int n)
{
	int		sum;
	int		p;

	sum = 0;
	p = 2;
	while (p <= n)
	{
		if (prime(p))
			sum = sum + p;
		++p;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
}	

int		ft_atoi(char *s)
{
	int		sign;
	int		result;
		
	sign = 1;
	result = 0;
	while (*s == '\t' || *s == '\v' || *s == ' '\
			|| *s == '\n' || *s == '\f' || *s == '\r')
		++s;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		++s;
	}
	while(*s >= '0' && *s <= '9')
	{
		result = (result * 10) + (*s - 48);
		++s;
	}
	return(result * sign);
}

void	add_prime_sum(char *s)
{
	int		n;
	
	n = ft_atoi(s);
	if (n < 0)
		write(1, "0\n", 2);
	else
		print_primes(n);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		add_prime_sum(av[1]);
	else
		write(1, "0\n", 2);
	return (0);
}
