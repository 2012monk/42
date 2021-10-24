/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:41:43 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/22 20:41:43 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	put_str(int fd, char *msg)
{
	while (*msg)
		write(fd, msg++, 1);
}

void	f_print(char *msg)
{
	put_str(F_STDOUT, msg);
}

void	throw_err_custom(char *prog, char *path, int err)
{
	if (err == 0)
		return ;
	put_str(F_STDERR, basename(prog));
	put_str(F_STDERR, ": ");
	put_str(F_STDERR, path);
	put_str(F_STDERR, ": ");
	put_str(F_STDERR, strerror(err));
	put_str(F_STDERR, "\n");
}
