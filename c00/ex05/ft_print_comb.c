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

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	comb(int cur, int pos, char out[3])
{
	if (cur > 10)
		return ;
	if (pos == 3)
	{
		write(1, out, 3);
		if (out[0] != '7')
		{
			ft_put_char(',');
			ft_put_char(' ');
		}
		return ;
	}
	out[pos] = '0' + cur;
	comb(cur + 1, pos + 1, out);
	out[pos] += 1;
	comb(cur + 1, pos, out);
}

void	ft_print_comb(void)
{
	char	out[3];

	comb(0, 0, out);
}
