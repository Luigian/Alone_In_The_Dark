/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 12:35:06 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/30 13:11:43 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/* option 1
int		is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n /= 2;
	if (n == 1)
		return (1);
	else
		return (0);
}
*/	
/* option 2	
int		is_power_of_2(unsigned int n)
{	
	if (n == 0)
		return (0);
	if ((n & (n - 1)) == 0)
		return (1);
	else
		return (0);
}
*/
/* option 3
int		is_power_of_2(unsigned int n)
{	
	
	
	if (!((n & (n - 1)) == 0) || n == 0)
		return (0);
	else
		return (1);
}
*/
/* option 4 */
int		is_power_of_2(unsigned int n)
{	
	return (!((n & (n - 1))) && n != 0);
}

int		main(void)
{
	printf("%d\n", is_power_of_2(64));
	printf("%d\n", is_power_of_2(1));
	printf("%d\n", is_power_of_2(3));
	printf("%d\n", is_power_of_2(0));
	return (0);
}
