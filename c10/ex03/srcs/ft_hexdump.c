#include "hexdump.h"
int	canonical;
int	total;
int	ever_dir;
int	**err_q;
char *prog;
int	len_toal(int ac, char **av)
{
	int		i;
	int		e;
	int		total;
	char	buf;
	int		fd;

	i = -1;
	total = 0;
	e = 0;
	while (++i < ac)
	{
		fd = open(av[i], O_RDWR);
		if (fd < 0)
		{
			ever_dir |= errno == EISDIR;
			err_q[i] = (int *) malloc(sizeof(int) * 2);
			err_q[i][0] = i;
			err_q[i][1] = errno;
			errno = 0;
			if (ever_dir || i != ac - 1 || total)
				continue ;
		}
		while (read(fd, &buf, 1) > 0)
			total++;
		if (errno)
			err_q[i + 1] = errno;
		if (fd > 3)
			close(fd);
	}
	return (total);
}

char	*cat_file(char **av, int size, int ac)
{
	int		fd;
	char	*dst;
	int		i;

	errno = 0;
	dst = (char *) malloc(sizeof(char) * (size + 1));
	i = 0;
	if (!dst)
		return (NULL);
	dst[size] = '\0';
	--av;
	while (ac-- && ++av)
	{
		fd = open(*av, O_RDWR);
		if (fd < 0)
			continue ;
		// 	throw_err(prog, *av);
		while (read(fd, &dst[i], 1) > 0)
			i++;
		// if (errno)
		// 	throw_err(prog, *av);
	}
	return (dst);
}


void    ft_hexdump(char buf[], int end)
{
	int			i;

	print_dec_to_hex(total, 7 + canonical);
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

void	cat_stdin(void)
{
	char	buf[17];
	int		i;

	i = -1;
	while (read(0, &buf[++i], 1))
	{
		if (i == 15)
		{
			ft_hexdump(buf, 16);
			total += i;
			i = 0;
		}
	}
	if (i)
		ft_hexdump(buf, i);
	print_dec_to_hex(total, 7 + canonical);
}
void	dump_err(char **av, char *prog, int ac)
{
	int	i;
	
	i = -1;
	while (++i < ac)
		throw_err_custom(prog, av[i], err_q[i]);
	if (err_q[i])
		throw_err_custom(prog, av[i - 1], err_q[i]);
	
}
void	dump(char *str, int size, char **av)
{
	int	i;
	int	batch;
	int	line;

	i = 0;
	batch = 16;
	line = 0;
	while (i < size)
	{
		if (i / 16 == size / 16)
			batch = size % 16;
		if (err_q[line])
		{
			throw_err_custom(prog, av[line], err_q[line]);
			line++;
			continue ;
		}
		ft_hexdump(&str[i], batch);
		i += 16;
		total += batch;
		line++;
	}
	if (total)
	{
		print_dec_to_hex(total, 7 + canonical);
		f_print("\n");
	}
}

int main(int ac, char *av[])
{
	int		size;
	char	*cont;
	
	err_q = (int **)malloc(sizeof(int *) * ((ac - 1) * 2));
	prog = av[0];
	if (!err_q)
		return (1);
	if (ac > 1)
		canonical = (av[1][0] == '-') && (av[1][1] = 'C');
	size = len_toal(ac - canonical - 1, av + canonical + 1);
	if (ac == 1 || (ac == 2 && canonical))
	{
		cat_stdin();
		return (0);
	}
	if (!size)
	{
		dump_err(av + canonical + 1, av[0], ac - canonical - 1);
		return (1);
	}
	cont = cat_file(av + canonical + 1, size, ac - canonical - 1);
	dump(cont, size, av + canonical + 1);
	return 0;
}
