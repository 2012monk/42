/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_serach_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:49:51 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/27 20:49:52 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	int	cmp;

	if (!root)
		return (0);
	cmp = cmpf(root->item, data_ref);
	if (cmp > 0)
		return (btree_search_item(root->left, data_ref, cmpf));
	if (cmp < 0)
		return (btree_search_item(root->right, data_ref, cmpf));
	return (root);
}
