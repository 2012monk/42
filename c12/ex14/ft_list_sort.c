/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:07:00 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/26 15:07:01 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap_data(t_list *head)
{
	void	*d;

	d = head->data;
	head->data = head->next->data;
	head->next->data = d;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*head;

	if (!begin_list || !*begin_list)
		return ;
	head = *begin_list;
	while (head && head->next)
	{
		if (cmp(head->data, head->next->data) > 0)
		{
			swap_data(head);
			head = *begin_list;
		}
		else
			head = head->next;
	}
}
