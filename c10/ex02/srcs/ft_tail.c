/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:36:57 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/20 14:36:59 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_tail.h"
#define BUF_SIZE 1024

int	is_directory(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	get_offset(char *option, char *num)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	if (option[0] != '-' || option[1] != 'c')
		return (-1);
	while ((9 <= num[i] && num[i] <= 13)
		|| num[i] == ' ')
		i++;
	if (!num[i])
		return (-1);
	while (num[i])
	{
		if (!('0' <= num[i] && num[i] <= '9'))
			return (-1);
		ret = (ret * 10) + num[i] - '0';
		i++;
	}
	return (ret);
}

void	print_file_name(char *name)
{
	f_print("==> ");
	f_print(name);
	f_print(" <==\n");
}

void	print_all(int ac, char **av, int bytes)
{
	int		i;
	t_node	*root;

	i = 2;
	while (++i < ac)
	{
		if (!is_directory(av[i]))
		{
			root = init_node(open(av[i], O_RDONLY));
			if (!root)
			{
				throw_err(av[0], av[i]);
				continue ;
			}
		}
		if (ac > 4)
			print_file_name(av[i]);
		if (!is_directory(av[i]))
			print_by_size(root, bytes);
		if (ac > 4 && i < ac - 1)
			f_print("\n");
		free_all(root);
	}
}

int	main(int ac, char **av)
{
	t_node	*root;
	int		bytes;

	bytes = get_offset(av[1], av[2]);
	if (bytes == -1)
	{
		errno = -1;
		throw_err(av[0], av[2]);
		return (1);
	}
	if (ac == 3)
	{
		root = init_node(0);
		print_by_size(root, bytes);
		return (0);
	}
	print_all(ac, av, bytes);
	return (0);
}
