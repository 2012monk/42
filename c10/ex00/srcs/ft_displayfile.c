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
int	main(int ac, char **av)
{
	int	fd;
	int	buf[1024];
	int	size;

	if (ac != 2)
	{
		if (ac == 1)
			write(1, "File name missing.\n", 19);
		else if (ac > 2)
			write(1, "Too many Arguments.\n", 20);
		return (1);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Cannot read file.\n", 18);
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
