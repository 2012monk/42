/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 11:08:21 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/17 11:08:22 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tower.h"

int	is_used_box(int x, int y, int value, t_status *status)
{
	return ((status->col_candidates[x]
			| status->row_candidates[y])
		& (1 << value));
}

void	place_box(int x, int y, int value, t_status *status)
{
	status->grid[x][y] = value;
	status->col_candidates[x] |= 1 << value;
	status->row_candidates[y] |= 1 << value;
}

void	delete_box(int x, int y, int value, t_status *status)
{
	status->grid[x][y] = 0;
	status->col_candidates[x] &= MASK ^ (1 << value);
	status->row_candidates[y] &= MASK ^ (1 << value);
}
