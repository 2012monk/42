/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:51:12 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/24 01:51:13 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	validate_key(char *key)
{
	if (!key)
		return (-1);
	while (*key && *key == ' ')
		key++;
	while ('0' <= *key && *key <= '9')
		key++;
	while (*key == ' ')
		key++;
	if (*key)
		return (-1);
	return (1);
}

int	validate_map(char **words)
{
	if (count_arr(words) != 2)
		return (-1);
	if (validate_key(words[0]) == -1)
		return (-1);
	return (1);
}
