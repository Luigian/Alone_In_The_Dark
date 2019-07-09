/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:32:20 by exam              #+#    #+#             */
/*   Updated: 2019/06/18 11:16:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_nbrlen(int n)
{
	int		len;
	
	len = 0;
	while (n > 0)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*ret;
	int		len;
	int		neg;
	int		i;
	
	len = 0;
	neg = 0;
	if (nbr == 0)
		++len;
	else if (nbr < 0)
	{
		++len;
		nbr *= -1;
		neg = 1;
	}
	len += ft_nbrlen(nbr);	
	i = len;
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	ret[i--] = '\0';
	if (neg)
	{
		ret[0] = '-';
		--len;	
	}
	while (len--)
	{
		ret[i] = (nbr % 10) + 48;
		nbr /= 10;
		--i;
	}
	return (ret);
}
