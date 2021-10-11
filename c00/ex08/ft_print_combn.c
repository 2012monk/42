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

int	g_length;

void	ft_put_char(char c)
{
	write(c, &c, 1);
}

void	comb(int cur, char out[], int remain, int size)
{
	if (cur > 10)
		return ;
	if (remain == 0)
	{
		write(1, out, size);
		if (out[0] != '0' + 10 - size)
			write(1, &", ", 2);
		return ;
	}
	out[size - remain] = cur + '0';
	comb(cur + 1, out, remain - 1, size);
	out[size - remain]++;
	comb(cur + 1, out, remain, size);
}

void	ft_print_combn(int n)
{
	char	out[10];

	comb(0, out, n, n);
}
