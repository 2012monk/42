/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:52:44 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/13 16:52:45 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *c)
{
	int	size;

	size = 0;
	while (*c++)
		size++;
	return (size);
}

int	is_overlap(char *c)
{
	int	cur;
	int	map[256];
	int	i;

	i = 0;
	while (i < 256)
		map[i++] = 0;
	while (*c)
	{
		cur = (int) *c;
		if (cur < 0)
			cur += 0xff + 1;
		map[cur]++;
		if (map[cur] > 1 || cur == '-' || cur == '+')
			return (1);
		c++;
	}
	return (0);
}

void	convert_to_base(int n, char *base, int radix)
{
	int	carry;
	int	digit;

	carry = n / radix;
	digit = n % radix;
	if (n < 0)
	{
		write(1, &"-", 1);
		carry *= -1;
		digit *= -1;
	}
	if (carry)
		convert_to_base(carry, base, radix);
	write(1, &base[digit], 1);
}

void	ft_putnbr_base(int nb, char *base)
{
	int	radix;

	radix = ft_strlen(base);
	if (radix <= 1)
		return ;
	if (is_overlap(base))
		return ;
	convert_to_base(nb, base, radix);
}
