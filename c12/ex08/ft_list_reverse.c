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
#include <stdlib.h>
#include <stdio.h>
int	main()
{
	t_list **list;
	t_list *tmp;
	char	*m[] = {"1","2","3","4","5"};

	list = malloc(sizeof(t_list *));
	*list = malloc(sizeof(t_list));
	tmp = *list;
	tmp->data = m[0];
	for (int i=1;i<5;i++)
	{
		tmp->next = malloc(sizeof(t_list));
		tmp = tmp->next;
		tmp->data = m[i];
	}
	ft_list_reverse(list);
	tmp = *list;
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp ->next;
	}
	
}
