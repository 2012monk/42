/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:34:13 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 19:37:34 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char *ret;
	char tmp;

	ret = str;
	while (*str)
	{
		if ('a' <= *str && 'z' >= *str)
			*str = *str - 32;
		str++;
	}
	return ret;
}
