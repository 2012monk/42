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

void	free_list(t_list *tmp)
{
	free_fct(tmp->data);
	free(tmp);
}

void	ft_list_remove_if(t_list *begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*head;
	t_list	*prev;

	if (!begin_list)
		return ;
	head = begin_list;
	while (head)
	{
		if (cmp(head->data, data_ref) == 0)
		{
			tmp = head;
			head = head->next;
			free_list(tmp);
			if (!prev)
				*begin_list = *head;
			else
				prev->next = head;
		}
		else
		{
			prev = head;
			head = head->next;
		}
	}
}
