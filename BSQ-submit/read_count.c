/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojoo <sojoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:24:56 by sojoo             #+#    #+#             */
/*   Updated: 2021/10/27 12:55:42 by sojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	count_size(char *argv)
{
	int		fd;
	int		i;
	int		size;
	char	buf[1000];

	size = 0;
	i = 1000;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (i == 1000)
	{
		i = read(fd, buf, 1000);
		if (i < 0)
			return (-1);
		size += i;
	}
	if (fd > 2)
		close(fd);
	return (size);
}

char	*read_map_file(char *argv)
{
	int		fd;
	int		size;
	char	*buf;

	size = count_size(argv);
	if (size < 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (size + 1));
	if (!buf)
		exit(1);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		free(buf);
		return (0);
	}
	read(fd, buf, size);
	buf[size] = '\0';
	close(fd);
	return (buf);
}
