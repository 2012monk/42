/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:55:30 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/22 22:55:31 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void	f_print(char *str)
{
	while (*str)
		write(1, str++, 1);
}
