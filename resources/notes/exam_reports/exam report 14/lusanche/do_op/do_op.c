/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 09:23:11 by exam              #+#    #+#             */
/*   Updated: 2019/08/13 09:32:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	do_op(int a, char *s, int b)
{
	int		result;

	result = 0;
	if (*s == '+')
		result = a + b;		
	else if (*s == '-')
		result = a - b;		
	else if (*s == '*')
		result = a * b;		
	else if (*s == '/')
		result = a / b;		
	else if (*s == '%')
		result = a % b;
	printf("%d\n", result);
}	

int		main(int ac, char **av)
{
	if (ac == 4)
		do_op(atoi(av[1]), av[2], atoi(av[3]));
	else
		write(1, "\n", 1);
	return (0);
}
