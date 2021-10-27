/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:59:58 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/27 20:59:59 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	apply(t_btree *root, int lv, int *l, void (*f)(void *i, int cl, int f))
{
	if (!root)
		return ;
	f(root->item, lv, *l == lv);
	if (lv == *l)
		*l = *l + 1;
	apply(root->left, lv + 1, l, f);
	apply(root->right, lv + 1, l, f);
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	current;

	current = 0;
	apply(root, 0, &current, applyf);
}
