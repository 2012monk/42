/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:22:26 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/27 20:22:27 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create(void *item)
{
	t_btree	*node;

	node = (t_btree *) malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->left = 0;
	node->right = 0;
	node->item = item;
	return (node);
}

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	t_btree	*head;

	head = *root;
	if (!root || !item)
		return ;
	if (!head)
	{
		head = btree_create(item);
		return ;
	}
	if (cmpf(head->item, item) > 0)
	{
		if (head->right)
			btree_insert_data(&head->right, item, cmpf);
		else
			head->right = btree_create(item);
	}
	else
	{
		if (head->left)
			btree_insert_data(&head->left, item, cmpf);
		else
			head->left = btree_create(item);
	}
}
