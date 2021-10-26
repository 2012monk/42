/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:06:54 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/26 16:06:55 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_creat_elem(void *data)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	return (node);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*head;

	head = *begin_list;
	if (!*begin_list)
	{
		*begin_list = ft_creat_elem(data);
		return ;
	}
	while (head->next)
		head = head->next;
	head->next = ft_creat_elem(data);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*head;
	void	*d;

	if (!begin_list || !*begin_list)
		return ;
	head = *begin_list;
	while (head && head->next)
	{
		if (cmp(head->data, head->next->data) > 0)
		{
			d = head->data;
			head->data = head->next->data;
			head->next->data = d;
			head = *begin_list;
		}
		else
			head = head->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_back(begin_list, data);
	ft_list_sort(begin_list, cmp);
}
