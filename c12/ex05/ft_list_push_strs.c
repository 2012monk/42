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

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*root;
	t_list	*tmp;

	root = (t_list *) malloc(sizeof(t_list));
	if (!root)
		return (NULL);
	while (size)
	{
		tmp = ft_creat_elem(*strs);
		if (!tmp)
			return (NULL);
		tmp->next = root;
		root = tmp;
		size--;
	}
	return (root);
}
