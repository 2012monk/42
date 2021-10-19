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

int	is_over_lap(unsigned char *c, int map[])
{
	int	i;

	i = 0;
	while (i < 256)
		map[i++] = -1;
	i = 0;
	while (c[i])
	{
		map[c[i]] += i + 1;
		if (map[c[i]] != i || c[i] == '-'
			|| c[i] == '+' || c[i] == ' ')
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
	if (e & 1)
		ret *= x;
	return (ret * ret);
}

int	convert_to_base(unsigned char *str, int map[], int digit, int radix)
{
	if (digit < 0)
		return (0);
	return (ft_pow(radix, digit) * (map[*str])
		+ convert_to_base(str + 1, map, digit - 1, radix));
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned char	*safe_str;
	int				sign;
	int				radix;
	int				digit;
	int				map[256];

	safe_str = (unsigned char *) str;
	sign = 1;
	radix = 0;
	digit = 0;
	while (base[radix])
		radix++;
	if (radix <= 1 || is_over_lap(base, map))
		return (0);
	while (*str == '\v' || *str == '\f'
		|| *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		sign *= 44 - *str++;
	while (map[str[digit]] != -1)
		digit++;
	return (sign * convert_to_base(str, map, digit - 1, radix));
}

#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("%d\n", ft_atoi_base("-------1000000000000", "01"));
	printf("%d\n", ft_atoi_base("7fffffff", "0123456789abcdef")); // __INT_MAX__
	printf("%d\n", ft_atoi_base("-80000000", "0123456789abcdef")); // -__INT_MAX__ - 1
	printf("%d\n",ft_atoi_base("1111111111111111111111111111111", "01")); // __INT_MAX__
	printf("%d\n",ft_atoi_base("-10000000000000000000000000000000", "01")); // -__INT_MAX__ - 1
	printf("%d\n",ft_atoi_base("10000000000000000000000000000000", "10")); // __INT_MAX__
	printf("%d\n", ft_atoi_base("abbacaab", "ab")); // 6
	printf("%d\n", ft_atoi_base("1a123", "0123456789")); // 1
	// Space Test
	printf("%d\n", ft_atoi_base("\t\v\r\n   \f  111", "01")); // 7
	printf("%d\n", ft_atoi_base("          \t\t\t\t \v\v\v \r \n+++++++++--+--+--+--+-1", "0123456789")); // -1
	printf("%d\n", ft_atoi_base("\t\t\t\t---7fffffff", "0123456789abcdef"));
	// OverFlow Test
	printf("%d\n", ft_atoi_base("\x88\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3", "\xd3\x88")); // 8192
	printf("%d\n", ft_atoi_base("\x88\xd3\x88\xd3", "\xd3\x88")); // 10
	printf("%d\n", ft_atoi_base("\xfe\xf3\xfe\xde\xde", "\xfe\xf3")); // 2
	// Validation Test
	printf("%d\n", ft_atoi_base("41", ""));
	printf("%d\n", ft_atoi_base("41", "1"));
	printf("%d\n", ft_atoi_base("--++-41", "1-+"));
	printf("%d\n", ft_atoi_base("020112", "10112"));
	printf("%d\n", ft_atoi_base("00000", "10-"));
	printf("%d\n", ft_atoi_base("  1  01001", "01"));
	return 0;
}