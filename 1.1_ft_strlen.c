/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:13:27 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/13 11:19:06 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int len;
	
	len = 0;
	while (*str++)
		++len;
	return (len);
}

int		main(void)
{
	printf("%d\n", ft_strlen("hola vato"));
	return (0);
}
