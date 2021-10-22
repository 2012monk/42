/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:40:34 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/22 20:40:35 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H

# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <libgen.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define F_STDIN 0

# define F_STDOUT 1

# define F_STDERR 2

# define LINE_SIZE 16

typedef struct s_node
{
	char			*data;
	struct s_node	*next;
	char			*file;
	int				size;
	int				err;
}	t_node;

extern int	g_ever_dir;

extern int	g_cur_size;

extern int	g_option;
void	f_print(char *msg);

int		is_eof(char *buf);

void	throw_err(char *prog, char *path);

int		batch_file(int fd, char buf[], int size);

void	print_dec_to_hex(unsigned long n, int size);

void	safe_print_char(char *str, int length);
void	print_ascii_hex(char *str, int size);
void	throw_err_custom(char *prog, char *path, int err);
char	*ft_strdup(char *src);
t_node	*add_err(char *name, int err, t_node *cur);
t_node	*data_shift(t_node *cur, char buf[17], int size);
void	ft_hexdump(char buf[], int end);
void	throw_err(char *prog, char *path);
void	free_node(t_node *node);
#endif
