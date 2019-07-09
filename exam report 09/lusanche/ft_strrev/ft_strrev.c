/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:00:08 by exam              #+#    #+#             */
/*   Updated: 2019/07/02 11:12:21 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while(s[i])
		++i;
	return (i);
}

void	ft_swap(char *a, char *b)
{
	char		temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	int		c;

	len = ft_strlen(str);
	c = len / 2;
	i = 0;
	--len;
	while (c--)
		ft_swap(&(str[i++]), &(str[len--]));
	return (str);
}
