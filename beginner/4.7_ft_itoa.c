/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:35:12 by exam              #+#    #+#             */
/*   Updated: 2019/08/26 22:07:30 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		nbr_len(int nbr)
{
	int		counter;

	counter = 0;
	while (nbr > 0)
	{
		++counter;
		nbr /= 10;
	}
	return (counter);
}

char	*ft_itoa(int nbr)
{
	int		slen;
	int		nlen;
	int		tlen;
	char	*result;

	slen = 0;
	nlen = 0;
	tlen = 0;
	if (nbr == 0)
		return ("0");
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		   return ("-2147483648");
		slen = 1;
		nbr *= -1;
	}
	nlen = nbr_len(nbr);
	tlen = slen + nlen;
	if (!(result = (char *)malloc(sizeof(char) * tlen + 1)))
		return (NULL);
	result[tlen] = '\0';
	while (tlen--)
	{
		if (!nbr)
			result[tlen] = '-';
		else
		{	result[tlen] = (nbr % 10) + 48;
			nbr /= 10;
		}
	}
	return (result);
}

int		main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}
