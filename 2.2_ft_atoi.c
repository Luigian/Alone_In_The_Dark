/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:40:35 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/13 11:50:54 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi(const char *str)
{
	int sign;
	long result;

	sign = 1;
	result = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||\
			*str == '\f' || *str == '\r' || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - 48);
		++str;
	}	
	return ((int)result * sign);
}

int		main(void)
{
	printf("%d\n", ft_atoi("   \t\n\v\f\r -1986abc "));
	return (0);
}
