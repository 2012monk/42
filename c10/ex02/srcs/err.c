/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:15:26 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/24 16:15:27 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	throw_err(char *prog, char *path)
{
	if (errno == 0)
		return ;
	if (errno == EISDIR)
	{
		errno = 0;
		return ;
	}
	put_str(F_STDERR, basename(prog));
	put_str(F_STDERR, ": ");
	if (errno != -1)
	{
		put_str(F_STDERR, path);
		put_str(F_STDERR, ": ");
		put_str(F_STDERR, strerror(errno));
	}
	else
	{
		put_str(F_STDERR, "illegal offset -- ");
	}
	put_str(F_STDERR, "\n");
	errno = 0;
}
