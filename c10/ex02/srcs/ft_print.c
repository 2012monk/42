/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:30:36 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/20 18:30:37 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	print_str(char *str, int size)
{
	write(1, str, size);
}

void	put_str(int fd, char *msg)
{
	while (*msg)
		write(fd, msg++, 1);
}

void	f_print(char *msg)
{
	put_str(F_STDOUT, msg);
}
