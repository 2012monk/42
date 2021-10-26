/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:59:53 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/25 10:59:54 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	print_files(int ac, char *av[], char *prog, int size)
{
	int		i;
	int		fd;
	char	*str;

	str = (char *) malloc(sizeof(char) * (size + 1));
	if (!str)
		return (-1);
	str[size] = '\0';
	i = -1;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0 || errno)
		{
			throw_err(prog, av[i]);
			continue ;
		}
		if (ac > 1 && !errno)
			print_file_name(av[i], ac > 1 && i > 0);
		print_buffer(size, str, fd);
		if (errno)
			throw_err(prog, av[i]);
	}
	free(str);
	return (1);
}

int	main(int ac, char *av[])
{
	if (ac < 3)
		return (0);
	if (av[1][0] != '-' || av[1][1] != 'c')
		return (1);
	if (!is_valid_number(av[2]))
	{
		errno = -1;
		throw_err(av[0], av[2]);
		return (1);
	}
	if (ac == 3)
		ft_echo(ft_atoi(av[2]));
	else
		print_files(ac - 3, &av[3], av[0], ft_atoi(av[2]));
	return (0);
}
