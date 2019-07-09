/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 20:13:49 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/08 20:43:58 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && accept[j])
	{
		if (s[i] == accept[j])
		{
			++i;
			j = 0;
		}
		else
			++j;
	}
	return (i);
}

int		main(void)
{
	printf("%zu\n", strspn("caricaamericja", "america"));
	printf("%zu\n", ft_strspn("caricaamericja", "america"));
	return (0);
}
