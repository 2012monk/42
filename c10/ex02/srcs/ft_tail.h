/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:40:50 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/20 17:40:50 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <libgen.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define BUF_SIZE 1024

# define BATCH_SIZE 4096

# define F_STDIN 0

# define F_STDOUT 1

# define F_STDERR 2

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	char			*data;
	int				n;
	int				size;
	int				line;
}	t_node;

void	throw_err(char *prog, char *path);

t_node	*init_node(int fd);

void	put_str(int fd, char *msg);

void	f_print(char *msg);

void	print_by_size(t_node *node, int size);

int		batch_file(int fd, char buf[], int size);

void	print_str(char *str, int size);

void	ft_echo(void);

void	free_all(t_node *node);

int		is_eof(char *buf);

#endif