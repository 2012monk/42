/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:40:58 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/22 20:40:59 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

t_node	*add_err(char *name, int err, t_node *cur)
{
	g_ever_dir |= err == EISDIR;
	errno = 0;
	cur->next = (t_node *) malloc(sizeof(t_node));
	cur->err = err;
	cur->file = name;
	if (!cur->next)
		return (NULL);
	return (cur->next);
}

t_node	*data_shift(t_node *cur, char buf[17], int size)
{
	cur->size = size;
	cur->err = 0;
	cur->next = (t_node *) malloc(sizeof(t_node));
	if (!cur->next)
		return (NULL);
	cur->data = ft_strdup(buf);
	return (cur->next);
}

void	free_node(t_node *node)
{
	if (node->data)
		free(node->data);
	free(node);
}
