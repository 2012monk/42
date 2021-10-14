/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:01:53 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/13 16:01:56 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while ((*str) != '\0')
	{
		str++;
		length++;
	}
	return (length);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
