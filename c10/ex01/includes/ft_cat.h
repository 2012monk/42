/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:14:44 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/20 13:14:45 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>

# define F_STDIN 0

# define F_STDOUT 1

# define F_STDERR 2

# define BUF_SIZE 1024

int		do_print(char *path);

void	ft_echo(void);

void	put_str(int fd, char *msg);

void	throw_err(char *prog, char *path);

#endif
