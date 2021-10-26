/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:14:21 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/23 12:14:22 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_creat(void *data)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	return (node);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*node;

	node = ft_creat(data);
	if (!node)
		return ;
	if (begin_list[0])
		node->next = begin_list[0];
	begin_list[0] = node;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*root;

	root = (t_list *) malloc(sizeof(t_list));
	if (!root)
		return (NULL);
	root->data = *strs++;
	while (--size)
	{
		ft_list_push_front(&root, *strs++);
	}
	return (root);
}
