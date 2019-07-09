/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:20:16 by exam              #+#    #+#             */
/*   Updated: 2019/05/21 09:38:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_power_of_2(unsigned int n)
{
	unsigned int p;

	p = 2;
	while (p <= 536870912)
	{
		if (n == (2 * p))
   			return (1);
		p = p * 2;
	}
	return (0);
}
