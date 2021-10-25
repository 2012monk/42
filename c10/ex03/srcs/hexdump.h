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

extern int	g_ever_dir;

extern int	g_size;

extern int	g_option;

void	f_print(char *msg);

int		is_eof(char *buf);

int		batch_file(int fd, char buf[], int size);

void	print_dec_to_hex(unsigned long n, int size);

void	safe_print_char(char *str, int length);
void	print_ascii_hex(char *str, int size);
void	throw_err(char *prog, char *path);
char	*ft_strdup(char *src);
void	ft_hexdump(char buf[], int end);
int		is_directory(char *name);
void	f_memcpy(void *dst, void *src, unsigned int len);
#endif
