/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 21:29:54 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/08 21:58:52 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	int		middle;

	i = 0;
	len = ft_strlen(str);
	middle = len / 2;
	--len;
	while (middle--)
	{
		ft_swap(&str[i], &str[len]);
		++i;
		--len;
	}
	return (str);
}

int		main(void)
{
	char	*s;

	s = malloc(sizeof(char));
	s[0] = 'a';
	s[1] = 'm';
	s[2] = 'e';
	s[3] = 'r';
	s[4] = '\0';
	printf("%s\n", ft_strrev(s));
	return (0);
}
