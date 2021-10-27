/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:57:00 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/27 20:57:01 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	l;
	int	r;

	if (!root)
		return (0);
	l = btree_level_count(root->left);
	r = btree_level_count(root->right);
	if (l > r)
		return (l + 1);
	return (r + 1);
}
