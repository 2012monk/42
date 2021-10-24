/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:22:12 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/18 16:22:13 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_abs(int n);
char	*from_dec_to_base(char *base, char *dst, int n, int radix);
int		from_base_to_dec(unsigned char *n, int radix, int map[]);
int		ft_strlen(char *str);
void	init(char *str, int size);

int	fill_base_map(unsigned char *base, int map[])
{
	int	i;

	i = -1;
	while (++i < 256)
		map[i] = -1;
	i = -1;
	while (base[++i])
	{
		map[base[i]] += i + 1;
		if (base[i] == ' ' || base[i] == '-'
			|| base[i] == '+' || map[base[i]] != i
			|| base[i] == '\n' || base[i] == '\t'
			|| base[i] == '\v' || base[i] == '\r' || base[i] == '\f')
			return (-1);
	}
	return (1);
}

int	ft_atoi_base(unsigned char *num, int radix, int map[])
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (num[i] == ' ' || (9 <= num[i] && num[i] <= 13))
		i++;
	while (num[i] == '-' || num[i] == '+')
	{
		sign *= 44 - num[i];
		i++;
	}
	return (from_base_to_dec((unsigned char *) &num[i], radix, map) * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*dst;
	int		converted;
	int		map[256];
	int		radix;

	radix = ft_strlen(base_from);
	if (ft_strlen(base_to) <= 1 || radix <= 1
		|| fill_base_map((unsigned char *) base_to, map) == -1
		|| fill_base_map((unsigned char *) base_from, map) == -1)
		return (NULL);
	converted = ft_atoi_base((unsigned char *) nbr, radix, map);
	dst = (char *) malloc(sizeof(char) * 34);
	if (!dst)
		return (NULL);
	init(dst, 34);
	*dst = base_to[0];
	if (converted == 0)
		return (dst);
	if (converted < 0)
		*dst++ = '-';
	from_dec_to_base(base_to, dst, converted, ft_strlen(base_to));
	if (converted < 0)
		return (dst - 1);
	return (dst);
}
