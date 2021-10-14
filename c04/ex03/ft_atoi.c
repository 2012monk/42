/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:04:49 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/13 16:04:50 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return (c == '\v'
		|| c == '\f'
		|| c == '\t'
		|| c == '\r'
		|| c == '\n'
		|| c == ' ');
}

int	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

int	char_to_dec(char *str, int digit)
{
	if (!is_digit(*str))
		return (0);
	return ((*str - '0') * digit + char_to_dec(str - 1, digit * 10));
}

int	ft_atoi(char *str)
{
	int		sign;
	char	*origin;

	sign = 1;
	origin = str;
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
		sign *= 44 - *str++;
	if (!is_digit(*str))
		return (0);
	while (is_digit(*str))
		str++;
	return (char_to_dec(str - 1, 1) * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char const *argv[])
// {
//     char n[] = "--++-----1234ab567";
//     printf("%d\n", ft_atoi(n));
//     printf("%d", atoi(n));
//     return 0;
// }