/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:11:09 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 21:42:46 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_dec_to_hex(unsigned long n, int size)
{
	if (size == 0)
		return ;
	print_dec_to_hex(n / 16, --size);
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

void	print_ascii_hex(char *str, int size, int pos)
{
	print_dec_to_hex((unsigned long) *str, 2);
	if (pos & 1)
		write(1, " ", 1);
	if (size <= 1)
		return ;
	print_ascii_hex(str + 1, size - 1, pos + 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned int		batch;
	int					length;
	char				*str;

	i = 0;
	str = (char *) addr;
	batch = 16;
	while (i * 16 < size)
	{
		print_dec_to_hex((unsigned long) str, 16);
		write(1, ": ", 2);
		if (i >= size / 16)
			batch = size % 16;
		print_ascii_hex(str, batch, 0);
		length = (16 - batch) * 2 + (17 - batch) / 2;
		while (length--)
			write(1, &" ", 1);
		safe_print_char(str, batch);
		write(1, "\n", 1);
		i++;
		str += 16;
	}
	return (addr);
}


int main(int argc, char const *argv[])
{
		char mem[] = {
		0x42, 0x6f, 0x6e, 0x6a, 0x6f, 0x75, 0x72, 0x20, 0x6c, 0x65, 0x73, 0x20, 0x61, 0x6d, 0x69, 0x6e,
		0x63, 0x68, 0x65, 0x73, 0x09, 0x0a, 0x09, 0x63, 0x20, 0x20, 0x65, 0x73, 0x74, 0x20, 0x66, 0x6f,
		0x75, 0x09, 0x74, 0x6f, 0x75, 0x74, 0x09, 0x63, 0x65, 0x20, 0x71, 0x75, 0x20, 0x6f, 0x6e, 0x20,
		0x70, 0x65, 0x75, 0x74, 0x20, 0x66, 0x61, 0x69, 0x72, 0x65, 0x20, 0x61, 0x76, 0x65, 0x63, 0x09,
		0x0a, 0x09, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x5f, 0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x0a, 0x0a,
		0x0a, 0x09, 0x6c, 0x6f, 0x6c, 0x2e, 0x6c, 0x6f, 0x6c, 0x0a, 0x20, 0x00, 0x72, 0x79, 0x0a, 0x0a,
		0x0a, 0x09, 0x6c, 0x6f, 0x6c, 0x2e, 0x6c, 0x6f, 0x6c, 0x0a, 0x20, 0x00, 0x72, 0x79, 0x0a, 0x0a,
		0x0a, 0x09, 0x6c, 0x6f, 0x6c, 0x2e, 0x6c, 0x6f, 0x6c, 0x0a, 0x20, 0x00, 0x72, 0x79, 0x0a, 0x0a,
		0x0a, 0x09, 0x6c, 0x6f, 0x6c, 0x2e, 0x6c, 0x6f, 0x6c, 0x0a, 0x20, 0x00 };

	// for (int i = 0; i < 140; i++)
	// {
	// 	write(1, "try\n",4);
	// 	ft_print_memory((void *) mem, i);
	// }
	ft_print_memory((void *) mem, 16);
	// ft_print_memory((void *) mem, 2);
	return 0;
}
