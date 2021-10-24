/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_dump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:01:29 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/22 20:01:30 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int		g_option;
int		g_total;
int		g_cur_size;
int		g_ever_dir;
char	*g_exec_name;
int		g_i;
char	g_buf[17];

void	cat_stdin(void)
{
	char	buf[17];
	int		i;

	i = 0;
	while (read(0, &buf[i], 1))
	{
		if (i == 15)
		{
			ft_hexdump(buf, 16);
			g_cur_size += i + 1;
			i = 0;
		}
		else
			i++;
	}
	if (i)
		ft_hexdump(buf, i);
	if (g_cur_size)
	{
		print_dec_to_hex(g_cur_size + i, 7 + g_option);
		f_print("\n");
	}
}

t_node	*add_file(t_node *cur, int fd)
{
	while (read(fd, &g_buf[g_i], 1) > 0)
	{
		if (g_i == 15)
			cur = data_shift(cur, g_buf, LINE_SIZE);
		g_i = (g_i + 1) % LINE_SIZE;
		g_total++;
	}
	return (cur);
}

void	join_file(char **av, int ac, t_node *root)
{
	int		fd;
	int		j;
	t_node	*cur;

	cur = root;
	j = -1;
	while (++j < ac)
	{
		fd = open(av[j], O_RDONLY);
		if (fd < 0)
			cur = add_err(av[j], errno, cur);
		if (fd < 0 && (g_ever_dir || j != ac - 1 || g_total))
			continue ;
		cur = add_file(cur, fd);
		if (errno)
			cur = add_err(av[j], errno, cur);
		if (fd > 3)
			close(fd);
	}
	if (g_i)
		cur = data_shift(cur, g_buf, g_i);
}

void	dump_node(t_node *root)
{
	t_node	*tmp;

	while (root)
	{
		if (root->err)
			throw_err_custom(g_exec_name, root->file, root->err);
		else if (root -> size)
		{
			ft_hexdump(root->data, root->size);
			g_cur_size += root->size;
		}
		tmp = root;
		root = root->next;
		free_node(tmp);
	}
	if (g_cur_size)
	{
		print_dec_to_hex(g_total, 7 + g_option);
		f_print("\n");
	}
}

int	main(int ac, char *av[])
{
	t_node	*root;

	g_exec_name = av[0];
	if (ac > 1)
		g_option = !(av[1][0] + av[1][1] - 'C' - '-');
	if (ac == 1 || (ac == 2 && g_option))
	{
		cat_stdin();
		return (0);
	}
	root = (t_node *) malloc(sizeof(t_node));
	if (!root)
		return (1);
	join_file(av + g_option + 1, ac - g_option - 1, root);
	dump_node(root);
	return (0);
}
