/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:45:32 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/13 17:45:33 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	fill_char_map(char *c, int map[])
{
	int	cur;
	int	i;

	i = 0;
	while (i < 256)
		map[i++] = -1;
	i = 0;
	while (c[i])
	{
		cur = c[i];
		if (cur < 0)
			cur += 0xff + 1;
		map[cur] += i + 1;
		if (map[cur] != i || cur == '-'
			|| cur == '+' || cur == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_pow(int x, int e)
{
	int	ret;

	if (!e)
		return (1);
	if (e == 1)
		return (x);
	ret = ft_pow(x, e / 2);
	ret *= ret;
	if (e & 1)
		ret *= x;
	return (ret);
}

int	convert_to_base(char *str, int map[], int digit, int radix)
{
	if (digit < 0)
		return (0);
	return (ft_pow(radix, digit) * map[(int) *str]
		+ convert_to_base(str + 1, map, digit - 1, radix));
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	radix;
	int	digit;
	int	map[256];

	sign = 1;
	radix = 0;
	digit = 0;
	while (base[radix])
		radix++;
	if (radix <= 1 || fill_char_map(base, map))
		return (0);
	while (*str == '\v' || *str == '\f'
		|| *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		sign *= 44 - *str++;
	while (map[(int) str[digit]] != -1)
		digit++;
	return (sign * convert_to_base(str, map, digit - 1, radix));
}
