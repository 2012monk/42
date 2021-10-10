/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:24:41 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 11:24:41 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_out[10];
char	g_delimiter[2];
int		g_length;
int		g_finished;

void	print(char *str, int length)
{
	write(1, str, length);
}

void	comb(int cur, int pos)
{
	if (cur > 10)
		return ;
	if (pos == g_length)
	{
		print(g_out, g_length);
		if (g_finished == 0)
			print(g_delimiter, 2);
		return ;
	}
	if (cur == 10 - g_length && pos == 0)
		g_finished = 1;
	g_out[pos] = '0' + cur;
	comb(cur + 1, pos + 1);
	g_out[pos]++;
	comb(cur + 1, pos);
}

void	ft_print_combn(int n)
{
	g_delimiter[0] = ',';
	g_delimiter[1] = ' ';
	g_length = n;
	comb(0, 0);
}

// int main(int argc, char const *argv[])
// {
// 	ft_print_combn(2);
// 	return 0;
// }
