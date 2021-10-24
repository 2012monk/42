/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:46:53 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/20 13:46:54 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	do_print(char *path)
{
	char	buf[BUF_SIZE];
	int		size;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	size = read(fd, buf, BUF_SIZE - 1);
	while (size)
	{
		if (errno)
			return (-1);
		buf[size] = '\0';
		write(F_STDOUT, buf, size);
		size = read(fd, buf, BUF_SIZE - 1);
	}
	if (size < 0)
		return (-1);
	if (fd > F_STDERR)
		close(fd);
	return (1);
}

void	ft_echo(void)
{
	char	buf;

	while (read(F_STDIN, &buf, 1))
		write(F_STDOUT, &buf, 1);
}

void	put_str(int fd, char *msg)
{
	while (*msg)
		write(fd, msg++, 1);
}

void	throw_err(char *prog, char *path)
{
	if (errno == 0)
		return ;
	put_str(F_STDERR, basename(prog));
	put_str(F_STDERR, ": ");
	put_str(F_STDERR, path);
	put_str(F_STDERR, ": ");
	put_str(F_STDERR, strerror(errno));
	put_str(F_STDERR, "\n");
	errno = 0;
}
