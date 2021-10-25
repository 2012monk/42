/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:12:39 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/25 16:12:39 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int		g_i;
char	g_buf[LINE_SIZE + 1];
int		g_size;
int		g_ever_dir;
int		g_option;

void	print_line(int fd)
{
	while (read(fd, &g_buf[g_i], 1) > 0)
	{
		if (errno)
			return ;
		g_i = (g_i + 1) % LINE_SIZE;
		if (g_i == 0)
		{
			ft_hexdump(g_buf, LINE_SIZE);
			g_size += LINE_SIZE;
		}
	}
}

void	read_file(char *file, int is_last, char *prog)
{
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 0 || errno)
	{
		throw_err(prog, file);
		if (g_ever_dir || g_size || !is_last)
			return ;
	}
	print_line(fd);
	if (errno)
		throw_err(prog, file);
	if (fd > 2)
		close(fd);
}

void	dump_files(int ac, char **av, char *prog)
{
	int			i;

	i = -1;
	while (++i < ac)
		read_file(av[i], i == ac - 1, prog);
	if (ac == 0)
		print_line(0);
	if (g_i)
		ft_hexdump(g_buf, g_i);
	if (g_size)
	{
		print_dec_to_hex(g_size + g_i, 7 + g_option);
		f_print("\n");
	}
}

int	main(int ac, char *av[])
{
	if (ac > 1)
		g_option = !(av[1][0] + av[1][1] - 'C' - '-');
	dump_files(ac - g_option - 1, &av[g_option + 1], av[0]);
	return (0);
}
