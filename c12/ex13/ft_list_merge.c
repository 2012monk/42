/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:00:04 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/26 15:00:05 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*head;

	if (!begin_list1 || !*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	head = *begin_list1;
	while (head->next)
		head = head->next;
	head->next = begin_list2;
}
