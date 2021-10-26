/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:23:56 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/26 15:23:57 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*reverse(t_list *head, t_list *prev)
{
	t_list	*tmp;
	void	*d;

	if (!head)
		return (prev);
	tmp = reverse(head->next, prev);
	d = head->data;
	head->data = tmp->data;
	tmp->data = d;
	return (prev->next);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	if (!begin_list)
		return ;
	reverse(begin_list->next, begin_list);
}
