/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:14:45 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/19 00:14:46 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	from_base_to_dec(unsigned char *n, int radix, int map[])
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	while (map[n[++i]] != -1)
		ret = (ret * radix) + map[n[i]];
	return (ret);
}

char	*from_dec_to_base(char *base, char *dst, int n, int radix)
{
	char	*origin;

	if (!n)
		return (dst);
	origin = from_dec_to_base(base, dst, n / radix, radix);
	*origin = base[ft_abs(n % radix)];
	return (origin + 1);
}

void	init(char *str, int size)
{
	while (size--)
		*str++ = '\0';
}
