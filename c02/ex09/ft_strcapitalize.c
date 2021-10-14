/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:42:00 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 19:50:00 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_upper_case(char c)
{
	return ('A' <= c && 'Z' >= c);
}

int	is_lower_case(char c)
{
	return ('a' <= c && 'z' >= c);
}

int	is_alphabet(char c)
{
	return (is_upper_case(c) || is_lower_case(c));
}

int	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

char	*ft_strcapitalize(char *str)
{
	int		is_first;
	char	*start;

	is_first = 1;
	start = str;
	while (*str)
	{
		if (!is_first && is_upper_case(*str))
			*str = *str - 'A' + 'a';
		if (is_first)
		{
			is_first = 0;
			if (is_lower_case(*str))
				*str = *str - 'a' + 'A';
		}
		is_first = !(is_alphabet(*str) || is_digit(*str));
		str++;
	}
	return (start);
}
