/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:02:06 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/13 12:31:16 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi_base(const char *str, int str_base)
{
	int sign;
	int num;
	long result;
	
	sign = 1;
	num = 0;
	result = 0;
	if (str_base < 2 || str_base > 16)
		return (0);
	while (*str == '\t' || *str == '\n' || *str == '\v'||\
			*str == '\f' || *str == '\r' || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num = *str - 48;
		else if (*str >= 'a' && *str <= 'f')
			num = (*str - 'a') + 10;
		else if (*str >= 'A' && *str <= 'F')
			num = (*str - 'A') + 10;
		else
			break;
		if (num < str_base)
			result = (result * str_base) + num;
		else
			break;
		++str;
	}
	return ((int)result * sign);
}

int		main(void)
{
	printf("%d\n", ft_atoi_base("   \t\n\v\f\r  1Cdef ", 13));
	return (0);
}	
