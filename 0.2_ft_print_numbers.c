/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:09:16 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/13 11:11:17 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	write(1, "0123456789", 10);
}

int		main(void)
{
	ft_print_numbers();
	write(1, "\n", 1);
	return (0);
}

