/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:41:03 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 09:48:44 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		n;
	t_list	*a;
	t_list	*b;
	
	a = lst;
	b = lst->next;
	n = cmp(a->data, b->data);
	if (!n)
	{
		lst = lst->next;
		lst->next = a;
		a->next = NULL;
	}
	return(lst);
}
