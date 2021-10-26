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

# define F_STDIN 0

# define F_STDOUT 1

# define F_STDERR 2

void	throw_err(char *prog, char *path);

void	put_str(int fd, char *msg);

void	f_print(char *msg);

int		batch_file(int fd, char buf[], int size);

void	print_str(char *str, int size);

void	ft_echo(int size);

int		ft_atoi(char *str);
int		is_valid_number(char *str);
int		read_bytes(int size, int fd, char *buf);
int		print_buffer(int size, char *buf, int fd);
void	print_file_name(char *name, int is_line);
#endif