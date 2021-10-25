/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:42:12 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/22 20:42:13 by seounlee         ###   ########.fr       */
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

void	ft_hexdump(char buf[], int end)
{
	int			i;

	print_dec_to_hex(g_size, 7 + g_option);
	if (g_option)
		f_print(" ");
	f_print(" ");
	i = -1;
	while (++i < 16)
	{
		if (i < end)
			print_dec_to_hex((unsigned long) buf[i], 2);
		else
			f_print("  ");
		if (i == 7 && g_option)
			f_print(" ");
		if (i != 15)
			f_print(" ");
	}
	if (g_option)
	{
		f_print("  |");
		safe_print_char(buf, end);
		f_print("|");
	}
	f_print("\n");
}
