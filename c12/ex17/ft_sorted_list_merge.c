/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:37:40 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/26 16:37:41 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*sorting(t_list *n1, t_list *n2, int (*cmp)())
{
	t_list	*head;
	t_list	*left;

	if (!n1 && !n2)
		return (0);
	head = n1;
	left = n2;
	if (!n1 || cmp(n1->data, n2->data) > 0)
	{
		head = n2;
		left = n1;
	}
	head->next = sorting(head->next, left, cmp);
	return (head);
}

void	ft_sorted_list_merge(t_list **begin_list1,
	t_list **begin_list2, int (*cmp)())
{
	sorting(*begin_list1, *begin_list2, cmp);
}
