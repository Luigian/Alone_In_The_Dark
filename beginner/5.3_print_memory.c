/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:24:51 by exam              #+#    #+#             */
/*   Updated: 2019/08/26 22:10:12 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_memory(const void *addr, size_t size)
{
	const char		*base;
	unsigned char	*str;
	char			line[17];
	size_t			i;
	int				j;
	int				nb;

	base = "0123456789abcdef";
	str = (unsigned char *) addr;
	i = 0;
	while (i < size || i % 16 != 0)
	{
		if (i < size)
		{
			nb = str[i] / 16;
			ft_putchar(base[nb]);
			nb = str[i] % 16;
			ft_putchar(base[nb]);
			line[i % 16] = str[i] >= 32 && str[i] <= 126 ? str[i] : '.';
		}
		else
			write (1, "  ", 2);
		++i;
		if (i % 2 == 0)
			write (1, " ", 1);
		if (i % 16 == 0)
		{
			j = 0;
			while (j < 16)
			{
				if (i - 16 + j >= size)
					break ;
				ft_putchar(line[j++]);
			}
			ft_putchar ('\n');
		}
	}
}

int		main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  42, 103};

	print_memory(tab, sizeof(tab));
	return (0);
}
