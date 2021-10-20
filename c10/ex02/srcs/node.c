/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:32:24 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/20 17:32:28 by seounlee         ###   ########.fr       */
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
		if (*buf++ == EOF)
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

int fill_node(t_node *root, int fd)
{
	t_node  *cur;
	cur = (t_node *) malloc(sizeof(t_node));
	if (!cur)
		return (-1);
	cur->data = (char *) malloc(sizeof(char) * (BATCH_SIZE + 1));
	cur->next = root->next;
	cur->prev = root;
	root->next = cur;
	cur->size = batch_file(fd, cur->data, BATCH_SIZE);
	cur->data[cur->size] = '\0';
	if (!cur->size)
		return (1);
	if (cur->size < 0)
		return (-1);
	if (fd == 0)
	{
		if (!is_eof(cur->data))
			return (fill_node(cur, fd));
	}
	if (cur->size == BATCH_SIZE)
		return (fill_node(cur, fd));
	return (1);
}

t_node  *init_node(int fd)
{
	t_node  *root;

	if (fd < 0)
		return (NULL);
	root = (t_node *) malloc(sizeof(t_node));
	if (!root)
		return (NULL);
	root->n = 0;
	if (fill_node(root, fd) == -1)
	{
		free(root);
		return (NULL);
	}
	return (root);
}

void	free_all(t_node *node)
{
	t_node *tmp;

	while (!node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}