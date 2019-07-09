/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:46:29 by exam              #+#    #+#             */
/*   Updated: 2019/04/30 12:58:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(const char *str, int str_base)
{
	int result;
	int i;
	int sign;
	int j;

	result = 0;
	i = 0;
	sign = 1;

	while (!(str[i] >= 48 && str[i] <= 57 || str[i] >= 97 && str[i] <= 102 || str[i] >= 65 && str[i] <= 70)) 
	{
		if (str[i] == '-')
		{
			sign = -1
		}
		i++;
	}
	else 
	{	
		j = 0;
		while (str_base > j && (str[i] >= 48 && str[i] <= 57 || str[i] >= 97 && str[i] <= 102 || str[i] >= 65 && str[i] <= 70))
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				result = str[i] + (result * 100);
			}
			if (str[i] >= 'a' && str[i] <= 'c')
			{
				result = str[i] + (result * 100);
			}
			if (str[i] >= 'd' && str[i] <= 'f')
			{
				result = str[i] + (result * 1000);
			}
			if (str[i] >= 'A' && str[i] <= 'C')
			{
				result = (str[i] + 32) + (result * 100);
			}
			if (str[i] >= 'D' && str[i] <= 'F')
			{
				result = (str[i] + 32) + (result * 1000);
			}
			i++;
			j++;
		}
	}
	result = result * sign;
	return (result);
}
