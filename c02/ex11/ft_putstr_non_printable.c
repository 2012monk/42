/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:05:16 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 20:13:59 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

int	is_printable(char c)
{
	return (c != 127 && c >= 32);
}

void	char_to_hex(int n)
{
	if (n < 0)
		n = 0xff + n + 1;
	put_char("0123456789abcdefg"[n / 16]);
	put_char("0123456789abcdefg"[(n % 16)]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_printable(*str) == 1)
			put_char(*str);
		else
		{
			put_char('\\');
			char_to_hex((int) *str);
		}
		str++;
	}
}
