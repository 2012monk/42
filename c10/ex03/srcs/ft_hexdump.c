/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:36:58 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/20 22:37:00 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hexdump.h"

void	print_dec_to_hex(unsigned long n, int size)
{
	if (size == 0)
		return ;
	print_dec_to_hex(n / 16, size - 1);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

void	safe_print_char(char *str, int length)
{
	if (*str == 127 || *str < 32)
		write(1, ".", 1);
	else
		write(1, str, 1);
	if (length <= 1)
		return ;
	safe_print_char(str + 1, length - 1);
}

void	print_ascii_hex(char *str, int size)
{
	print_dec_to_hex((unsigned long) *str, 2);
	if (size <= 1)
		return ;
	print_ascii_hex(str + 1, size - 1);
}

int file_size(char *file)
{
	int     fd;
	char    buf;
	int     size;

	size = 0;
	fd = open(file, O_RDWR);
	if (fd < 0)
		return (-1);
	while (read(fd, &buf, 1))
		size++;
	close(fd);
	return (size);
}

void    ft_hexdump(char buf[], int canonical, int index, int end)
{
	int			i;

	print_dec_to_hex(index, 7 + canonical);
	if (canonical)
		f_print(" ");
	f_print(" ");
	i = -1;
	while (++i < 16)
	{
		if (i < end)
			print_dec_to_hex((unsigned long) buf[i], 2);
		else
			f_print("  ");
		if (i == 7 && canonical)
			f_print(" ");
		if (i != 15)
			f_print(" ");
	}
	if (!canonical)
	{
		f_print("\n");
		return ;
	}
	f_print("  |");
	safe_print_char(buf, end);
	f_print("|\n");
}
void	clear(char buf[])
{
	int	i;

	i = -1;
	while (++i <17)
		buf[i] = 0;
}
int	dump(int ac, char **av, int canonical, char *prog)
{
	int		fd;
	int		i;
	char	buf[17];
	int		size;
	int		offset;
	int		total;

	i = -1;
	offset = 0;
	size = 0;
	total = 0;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
		{
			throw_err(prog, av[i]);
			continue ;
		}
		size = batch_file(fd, buf, LINE_SIZE);

		while (size)
		{
			// return 1;
			// offset = 0;
			// if (size < LINE_SIZE && i < ac - 1)
			// {
			// 	offset = size;
			// 	break ;
			// }
			ft_hexdump(buf, canonical, total, size);
			// printf("%d %d %s\n", size, errno, strerror(errno));
			total += size;
			size = batch_file(fd, buf, LINE_SIZE);
		}
		close(fd);
	}
	print_dec_to_hex(total, 7 + canonical);
	f_print("\n");
	return 1;
}

// char	*join_file(int ac, char **av)
// {
// 	int		size;
// 	int		i;
// 	int		j;
// 	int		tmp;
// 	char	*dst;
// 	int		fd;

// 	i = 0;
// 	size = 0;
// 	while (++i < ac)
// 	{
// 		tmp = file_size(av[i]);
// 		if (tmp < 0)
// 			continue ;
// 		size += tmp;
// 	}
// 	dst = (char *) malloc(sizeof(char) * (size + 1));
// 	i = 0;
// 	j = 0;
// 	while (i < ac)
// 	{
// 		fd = open(av[i], O_RDWR);
// 		if (fd < 0)
// 		{
// 			throw_err(av[0], av[i]);
// 			continue ;
// 		}
		
// 	}
// }

int main(int ac, char **av)
{
	int canonical;
	int fd;
	int i;
	char	buf[17];

	if (ac == 1)
		fd = 0;
	i = 0;
	canonical = 0;
	buf[16] = '\0';
	if (ac > 1)
		canonical = (av[1][0] == '-') && (av[1][1] = 'C');
	dump(ac - 1 - canonical, av + 1 + canonical, canonical, av[0]);
	return (0);
}