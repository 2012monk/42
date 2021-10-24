/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:57:37 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/24 15:57:38 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	batch_file(int fd, char buf[], int size)
{
	if (fd < 0)
		return (-1);
	return (read(fd, buf, size));
}

int	is_eof(char *buf)
{
	while (*buf)
	{
		if (*buf++ == -1)
			return (1);
	}
	return (0);
}

void	count_line(t_node *node)
{
	int	i;

	if (!node || !node->size)
		return ;
	i = -1;
	while (node->data[++i])
		node->line += node->data[i] == '\n';
}
