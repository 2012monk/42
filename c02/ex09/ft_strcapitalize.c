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


char	*ft_strcapitalize(char *str)
{
	int	is_first;

	is_first = 1;
	while (*str)
	{
		if (!is_first && is_upper_case(*str))
			*str = *str + 32;
		if (is_first && is_lower_case(*str))
		{
			is_first = 0;
			*str = *str - 32;
		}

		if (*str == ' ')
			is_first = 1;
		str++;
	}
}
