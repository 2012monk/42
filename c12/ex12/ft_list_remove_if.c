/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:08:31 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/24 18:08:32 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list *begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*prev;

	if (!begin_list)
		return ;
	while (begin_list)
	{
		tmp = begin_list;
		if (cmp(begin_list->data, data_ref) == 0)
		{
			begin_list = begin_list->next;
			free_fct(tmp->data);
			free(tmp);
		}
		else
			begin_list = begin_list->next;
	}
}
