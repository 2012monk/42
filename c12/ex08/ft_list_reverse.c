/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:44:32 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/24 16:44:33 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*rec_reverse(t_list *node, t_list *prev)
{
	t_list	*tmp;

	if (!node)
		return (prev);
	tmp = node->next;
	node->next = prev;
	return (rec_reverse(tmp, node));
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*begin;

	begin = *begin_list;
	*begin_list = rec_reverse(begin, NULL);
}
