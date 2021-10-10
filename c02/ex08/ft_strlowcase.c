/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:40:24 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 19:41:40 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char *ret;

	ret = str;
	while (*str)
	{
		if ('A' <= *str && *str <= 'Z')
			*str = *str + 32;
		str++;
	}
	return ret;
}
