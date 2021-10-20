/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:30:36 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/20 18:30:37 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
void    print_str(char *str, int size)
{
    write(1, str, size);
}
void	put_str(int fd, char *msg)
{
	while (*msg)
		write(fd, msg++, 1);
}

void    f_print(char *msg)
{
    put_str(F_STDOUT, msg);
}
void    print_by_size(t_node *node, int size)
{
    if (size <= 0 || !node)
        return ;
    if (node->size >= size)
    {
        print_str(&node->data[node->size - size], size);
        return ;
    }
    print_str(node->data, node->size);
    print_by_size(node->next, size - node->size);
}

void    print_by_line(t_node *node, int size)
{
    int i;
    int j;

    i = node->size;
    j = 0;
    if (node->data[i - 1] == '\n'
        && node->size < BATCH_SIZE)
        size++;
    while (--i >= 0 && size)
        size -= node->data[i] == '\n';
    print_str(node->data, node->size - i + 1);
    if (size)
        print_by_line(node->next, size);
}

void	throw_err(char *prog, char *path)
{
	if (errno == 0)
		return ;
	put_str(F_STDERR, basename(prog));
	put_str(F_STDERR, ": ");
    if (errno != -1)
    {

        put_str(F_STDERR, path);
        put_str(F_STDERR, ": ");
	    put_str(F_STDERR, strerror(errno));
    }
    else
    {
        put_str(F_STDERR, "illegal offset -- ");
    }
	put_str(F_STDERR, "\n");
	errno = 0;
}