/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:57:38 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/24 22:01:38 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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
		if (nbr == -2147483648)
			return ("-2147483648");		
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

int		main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}
