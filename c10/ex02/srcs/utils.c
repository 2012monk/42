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

int	is_valid_number(char *str)
{
	while (*str && *str == ' ')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	ft_echo(int size)
{
	char	*dst;

	dst = (char *) malloc(sizeof(char) * (size + 1));
	if (!dst)
		return ;
	dst[size] = '\0';
	print_buffer(size, dst, 0);
}

int	read_bytes(int size, int fd, char *buf)
{
	int	i;
	int	head;

	i = 0;
	head = 0;
	while (read(fd, &buf[i], 1) > 0)
	{
		if (!size)
			continue ;
		i = (i + 1) % size;
		if (i == head)
			head = (head + 1) % size;
	}
	if (fd > 2)
		close(fd);
	if (errno)
		return (-1);
	if (i < head)
		return (i);
	return (head);
}

int	print_buffer(int size, char *buf, int fd)
{
	int	i;
	int	cnt;

	if (fd < 0 || errno == EISDIR)
		return (1);
	i = -1;
	cnt = size;
	while (++i < size)
		buf[i] = '\0';
	i = read_bytes(size, fd, buf);
	if (i < 0)
		return (-1);
	while (size && cnt-- && buf[i])
	{
		write(1, &buf[i], 1);
		i++;
		i %= size;
	}
	return (1);
}

void	print_file_name(char *name)
{
	f_print("==> ");
	f_print(name);
	f_print(" <==\n");
}
