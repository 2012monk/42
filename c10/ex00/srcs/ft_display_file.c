/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:36:00 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/20 09:36:01 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	f_print(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	exception(int ac)
{
	if (ac == 1)
		f_print("File name missing.\n", 2);
	else if (ac > 2)
		f_print("Too many arguments.\n", 2);
}

int	main(int ac, char **av)
{
	int	fd;
	int	buf[1024];
	int	size;

	if (ac != 2)
	{
		exception(ac);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		f_print("Cannot read file.\n", 2);
		return (1);
	}
	size = read(fd, buf, 1024);
	while (size != 0)
	{
		write(1, buf, size);
		size = read(fd, buf, 1024);
	}
	close(fd);
	return (0);
}
