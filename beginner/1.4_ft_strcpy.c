/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:51:23 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/22 20:52:57 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2)
{
	char	*beg;
	
	beg = s1;
	while(*s2)
	{
		*s1 = *s2;
		++s1;
		++s2;
	}
	*s1 = *s2;
	return (beg);
}

int		main(void)
{
	char s[50];
	printf("%s\n", ft_strcpy(s, "kamelot"));
	return (0);
}

