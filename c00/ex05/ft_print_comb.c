/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:23:44 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 11:23:45 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_out[5];
int		g_first;

void	comb(int cur, int pos)
{
	if (cur > 10)
		return ;
	if (pos == 3)
	{
		if (g_first != 1)
			write(1, g_out, 5);
		else
			write(1, g_out, 3);
		return ;
	}
	if (cur == 7 && pos == 0)
		g_first = 1;
	g_out[pos] = '0' + cur;
	comb(cur + 1, pos + 1);
	g_out[pos] += 1;
	comb(cur + 1, pos);
}

void	ft_print_comb(void)
{
	g_first = 0;
	g_out[3] = ',';
	g_out[4] = ' ';
	comb(0, 0);
}
