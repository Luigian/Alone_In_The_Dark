/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 21:40:39 by lusanche          #+#    #+#             */
/*   Updated: 2019/06/17 23:03:20 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_nbrlen(int n)
{
	int		count;
	
	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		++count;
	}
	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*s;
	int		i;

	len = ft_nbrlen(nbr);
	i = len;
	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[i] = '\0';
	if (nbr < 0)
	{
		nbr *= -1;
		s[0] = '-';
		--len;
	}
	while (len--)
	{
		s[--i] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (s);
}

int		main(void)
{
	printf("%s\n", ft_itoa(1));
	return (0);
}
