/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:59:20 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/23 11:59:21 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*node;

	node = ft_creat_elem(data);
	if (!node)
		return ;
	if (begin_list[0])
		node->next = begin_list[0];
	begin_list[0] = node;
}
