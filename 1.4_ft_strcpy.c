/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:12:21 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/30 11:31:42 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int		i;
	
	i = 0;
	while (*s2)
	{
		*s1++ = *s2++;
		++i;
	}
	*s1 = *s2;
	return (s1 - i);
}

int		main(void)
{
	char s[50];
	printf("%s\n", ft_strcpy(s, "kamelot"));
	return (0);
}
